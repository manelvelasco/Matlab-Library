function [exectime, data] = processor(seg, data)
switch seg
 case 1
    %get state
    a=data.a; ts=data.ts; wo=data.wo; P=data.P;   Q=data.Q;   dw=data.dw; dV=data.dV; f=data.f; V=data.V;
    m=data.m; n=data.n;   mp=data.mp; Lv=data.Lv; ts=data.ts; t=data.t;   Vn=data.Vn; kif=data.kif; kpf=data.kpf;
   
    
    ia= ttAnalogIn(1);    
    ib= ttAnalogIn(2);
    
    %------------------ 
    %Secondary control 
    %------------------
    
    switch data.policy
        case 'CENTRAL'
            if a==1
                %This is the mcc controller, it computes the correction and sends
                %it to the rest of nodes

                %let's compute the correction 
                
                ferror=(wo-f*2*pi);
                data.integral=data.integral+ts*ferror;
                dw=kif*data.integral+kpf*ferror;
                
                %let's send it 
                
                ttSendMsg([1 0],[a,data.f,data.V,Q,P,dw,dV,ferror],80);
            else
                %this is the slave, it gets data from the network and uses
                %it
                
                msg=ttGetMsg;
                if isempty(msg)
                else
                    dw=msg(6);
                    dv=msg(7);
                end
            end
        case 'DISTRIBUTED1'
            if a==1
                %This is the mcc controller, it computes the correction and sends
                %it to the rest of nodes

                %let's compute the correction 
                
                ferror=(wo-f*2*pi);
                data.integral=data.integral+ts*ferror;
                dw=kif*data.integral+kpf*ferror;
                
                %let's send it 
                
                ttSendMsg([1 0],[a,data.f,data.V,Q,P,dw,dV,ferror],80);
            else
                %this is the slave, it gets data from the network and uses
                %it
                
                msg=ttGetMsg;
                if isempty(msg)
                else
                    f_rx=msg(2);
                    ferror=(wo-f_rx*2*pi);
                    data.integral=data.integral+ts*ferror;
                    dw=kif*data.integral+kpf*ferror;
                    
                end
            end
        case 'DISTRIBUTED2'
            if a==1
                %This is the mcc controller, it computes the correction and sends
                %it to the rest of nodes

                %let's compute the correction 
                
                ferror=(wo-f*2*pi);
                data.integral=data.integral+ts*ferror;
                dw=kif*data.integral+kpf*ferror;
                
                %let's send it 
                
                ttSendMsg([1 0],[a,data.f,data.V,Q,P,dw,dV,ferror],80);
            else
                %this is the slave, it gets data from the network and uses
                %it
                
                msg=ttGetMsg;
                if isempty(msg)
                else
                    ferror=msg(8);
                    data.integral=data.integral+ts*ferror;
                    dw=kif*data.integral+kpf*ferror;
                end
            end
        case 'AVERAGING'
            %Send messages all to all
            data.dataf(a)=f;
            data.datav(a)=V;
            data.dataq(a)=Q;
            msg=ttGetMsg;
            while  ~isempty(msg)
               data.dataf(msg(1))=msg(2);
               data.datav(msg(1))=msg(3);
               data.dataq(msg(1))=msg(4);
               msg=ttGetMsg;
            end
            f_media=sum(data.dataf)/(sum(data.dataf>0));
            v_media=sum(data.datav)/(sum(data.dataf>0));
            q_media=sum(data.dataq)/(sum(data.dataf>0));
            
            ferror=(wo-f_media*2*pi);
            data.integral=data.integral+ts*ferror;
            dw=kif*data.integral+kpf*ferror;
            
            ttSendMsg([1 0],[a,data.f,data.V,Q,P,dw,dV,0],80);
            
         case 'CONSENSUS'
            %Send messages all to all
            data.dataf(a)=f;
            data.datav(a)=V;
            data.dataq(a)=Q;
            data.datadw(a)=dw;
            msg=ttGetMsg;
            while  ~isempty(msg)
               data.dataf(msg(1))=msg(2);
               data.datav(msg(1))=msg(3);
               data.dataq(msg(1))=msg(4);
               data.datadw(msg(1))=msg(6);
               msg=ttGetMsg;
            end
            
          
uc=0.075*sum(data.datadw(1:4)-data.dw); % 0.075
e=0.01*sum(f-data.dataf(1:4))+10*(50-f); %15*(50-f)
wpunt=1*e+1*uc;
data.integral=data.integral+ts*wpunt;
dw=data.integral-f;
           
            
            ttSendMsg([1 0],[a,data.f,data.V,Q,P,dw,dV,0],80);   
            
    end
    
    %Droop algorithm
    t=t+ts; ph=(wo+dw-m*P)*t-mp*P;if ph>(2*pi) t=((ph-2*pi)+mp*P)/(wo+dw-m*P); end;
    va=(Vn+dV-n*Q)*sin(ph); vb=-(Vn+dV-n*Q)*cos(ph);
    va=va+Lv*wo*ib; vb=vb-Lv*wo*ia;
    
    p=(3/2)*(va*ia+vb*ib);q=(3/2)*(-va*ib+vb*ia);
    V=sqrt(va^2+vb^2); f=(wo+dw-m*P)/(2*pi);

    
    %Filter active and reactive power signals
    P = (data.num(1)*p+data.num(2)*data.p-data.den(2)*data.P)/data.den(1);
    Q = (data.num(1)*q+data.num(2)*data.q-data.den(2)*data.Q)/data.den(1);
    
    %save state
    data.p=p; data.q=q; data.P=P; data.Q=Q; data.dw=dw;
    data.dV=dV; data.Vn=Vn; data.t=t; data.V=V; data.f=f;
    
    data.va=va;
    data.vb=vb;
    

  
 
  
  exectime = (100e-6)/2;
 case 2
  ttAnalogOut(1, data.P); % Send message (80 bits) to node 1 (controller)
  ttAnalogOut(2, data.dw)
  ttAnalogOut(3, data.V)
  ttAnalogOut(4, data.f)
  ttAnalogOut(5, data.va)
  ttAnalogOut(6, data.vb)
  exectime = -1;
end