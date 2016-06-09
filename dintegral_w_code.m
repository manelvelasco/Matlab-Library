function [exectime, data] = dintegral_w_code(seg, data)

switch seg
 case 1
  data.f = ttAnalogIn(1);
  data.v = ttAnalogIn(2);
  data.en = ttAnalogIn(3);


picontroller=0;
%persistent ac; if isempty(ac); ac=0; end;
ts=100e-6;
e_w=data.en*data.f;
data.integrator=data.integrator+ts*e_w;
picontroller=0.5*1.2*data.integrator+0.5*0.1*e_w;
data.delta=picontroller ;
  
  exectime = (100e-6)/2;
 case 2
  ttAnalogOut(1, data.delta); % Send message (80 bits) to node 1 (controller)
  exectime = -1;
end