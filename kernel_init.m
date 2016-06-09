function kernel_init(arg)
global ts wo m n mp numPQ denPQ Vn Lv politik_matrix kpf kif num_generators

a=arg(1);
%Persistent variables
   data.num=numPQ;
   data.den=denPQ;
 
   data.a=a;
   data.ts=ts;
   data.wo=wo;
   data.P=0;
   data.Q=0;
   data.dw=0;
   data.dV=0;
   data.Vn=Vn;
   data.V=0;
   data.m=m;
   data.n=n;
   data.mp=mp;
   data.Lv=Lv;
   data.ts=ts;
   data.t=0;
   data.va=0;
   data.vb=0;
   data.p=0;
   data.q=0;
   data.f=wo/(2*pi);
   data.kif=kif;
   data.kpf=kpf;
   data.integral=0;
   data.policy=politik_matrix{a}
   data.dataf=zeros(1,num_generators)
   data.datav=zeros(1,num_generators)
   data.dataq=zeros(1,num_generators)
   data.datadw=zeros(1,num_generators)
   
   %create the task
   ttInitKernel('prioEDF');
   ttCreatePeriodicTask('dintegral_w_task', 0, 100e-6, 'processor',data);
end