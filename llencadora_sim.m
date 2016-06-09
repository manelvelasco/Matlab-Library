clc; clear all; %close all; 
global ts
global wo
global m
global n
global mp kif kpf
global numPQ denPQ Vn Lv
global politik_matrix
global num_generators
politik='CONSENSUS'
politik_matrix={politik politik politik politik politik politik politik politik politik politik politik}


ts=100e-6; 
data_rate=0.01;
%%-----politik Legend--------------
% Sencondaryless= 1;
% Central_Integral= 2;
% Distributed_Integral= 3;
% Warrior= 4;
% Consensu= 5;
% Distributed_integral_w=6;
%%----------------------------------
%tr=.5; %Limit inferior 0.7e-3 tolerable si 100 Mb/s i 84B amb 32 nodes 
tstop=10;
mpm=zeros(1,32);
Lvm=zeros(1,32);
mpm(4)=1*0.5e-6 ;mpm(8)=1*0.5e-6;mpm(16)=0.5*0.5e-6;mpm(32)=0.25*0.5e-6;
Lvm(4)=1*12.8e-6 ;Lvm(8)=1*12.8e-6;Lvm(16)=0.5*12.8e-6;Lvm(32)=0.25*12.8e-6;
tr=10;
loss=0;



% 16 i 32 amb zero loss

% Pau_Pol_4_Nodes_8_Perd_0.2_TxRate_0.3
for politik= 6%%[2 3 4 5]
    for nodes= 4% [4 8 16 32]%[32] %[4 8 16 32]
     for loss= 0% [0.2 0.4]% [0 0.1 0.2 0.3 0.4 0.5] %[0.2 0.3] %[0 .2 .4 .6 .8 ]
            for tr= [0.01] %[0.01 0.1 0.3 0.5 1]% [0 0.01 0.1 0.3 0.5 1]
                %politik=2; nodes=8; loss=0; tr=2;
                file_name=['Pau_Pol_' num2str(politik) '_Nodes_' num2str(nodes) '_Perd_' num2str(loss) '_TxRate_' num2str(tr) ];
                display(file_name)
                model=['nodes' num2str(nodes)];
                KSencondaryless= (politik==1);
                KCentral_Integral= (politik==2);
                KDistributed_Integral= (politik==3);
                KWarrior= (politik==4);
                KDegenerated= (politik==5);
                KDistributed_Integral_w= (politik==6);
                tot=nodes;
                
                
                
                Vn=230*sqrt(2); fo=50; wo=2*pi*fo; num_generators=tot; num_loads=tot; num_lines=tot; num_loads_act=1;
                
                
                kernel_offset=zeros(1,num_generators);
                kernel_drift=ones(1,num_generators)*0.1-0.05;
                
                minRline=1.3e-3; maxRline=8.8e-3; minLline=maxRline/(tand(70)*wo); maxLline=minRline/(tand(20)*wo);
                minRL=0.21; maxRL=0.45; minLL=0.47e-3; maxLL=1e-3;
                tL=1e10*ones(1,num_loads_act); %Temps en el que les carregues es desconecten
                tL(1)=tstop/2;
                rand('seed',2);
                Rline=minRline+(maxRline-minRline)*rand(1,num_lines);
                rand('seed',3);
                Lline=minLline+(maxLline-minLline)*rand(1,num_lines);
                rand('seed',5);
                RL=minRL+(maxRL-minRL)*rand(1,num_loads);
                rand('seed',7);
                LL=minLL+(maxLL-minLL)*rand(1,num_loads);
                RLa_pre=minRL*ones(1,num_loads_act)*4/tot;
                RLa_pos=maxRL*ones(1,num_loads_act)*4/tot;
                rand('seed',11); %11    4-17
                transmission_phase=round(1000*tr*rand(1,num_generators))/1000;
                m=10e-6; n=100e-6; mp=mpm(nodes); Lv=Lvm(nodes); 
                num=[0.02*wo]; den=[1 0.02*wo]; sysd=c2d(tf(num,den),ts,'tustin'); [numPQ,denPQ]=tfdata(sysd,'v'); 
                kpf=0.5*0.1; kif=0.5*1.2; kpV=0*0.5*0.1; kiV=0*0.5*0.8; kpQ=0*10e-6; kiQ=0*80e-6; % ganancias PI del control secundario
                %ic=round(1000*tr*rand(1,num_generators))/10
                %rand('seed',15);
                ic=0*[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]*wo/(2*pi);
                %ic=round(1000*tr*rand(1,num_generators))/100+round(1000*tr*rand(1,num_generators))/10
                dr=[0*10*2e-8 0 0 0];
                try
                %sim(model);
                catch e
                    fid = fopen('ERRORS.txt', 'a+');
                    fprintf(fid,  e.message);
                    fprintf('/n /r');
                    fclose(fid);
                end

                %figure; plot(t,P); title('active power (W)');
                % figure; plot(t,Q); title('reactive power (VAr)');
                % figure; plot(t,V); title('voltage (V)');
                % figure; plot(t,f); title('frequency (Hz)');
                %figure; plot(t,Data1Rx,'b',t,Data2Rx,'r'); title('Sent Data');
                %figure;plot(schedule.time,schedule.values);
                file_name=['Pau_Pol_' num2str(politik) '_Nodes_' num2str(nodes) '_Perd_' num2str(loss) '_TxRate_' num2str(tr) '.mat' ];
                save (file_name)
                
                h=figure; plot(t,P(:,1:end-1), 'LineWidth', 2); hold on
                  plot(t,P(:,end),'k', 'LineWidth', 2);
                  set(gca, 'FontSize', 24);
                  %title(['Strategy n. ' num2str(politik)]);
                  grid on
                  ylabel('Active power (W)')
                  xlabel('Time (s)')
                  ylim([0 6*10^5]);
                  %saveas(h,['../P_' file_name '.eps'])
                  h1=figure; plot(t,f(:,1:end-1), 'LineWidth', 2); hold on
                  plot(t,f(:,end),'k', 'LineWidth', 2);
                  set(gca, 'FontSize', 24);
                  %title(['Strategy n. ' num2str(politik)]);
                  grid on;
                  ylabel('Frequency (Hz)');
                  xlabel('Time (s)');
                  ylim([49 50.5]);
                  %saveas(h1,['../W_' file_name '.eps']);
            end
        end
    end
end










