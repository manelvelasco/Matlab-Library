function dintegral_w_init(arg)

   ttInitKernel('prioEDF') 
   data.en=0;
   data.f=0;
   data.v=0;
   data.integrator=0;
   ttCreatePeriodicTask('dintegral_w_task', 0, 100e-6, 'dintegral_w_code',data);
end