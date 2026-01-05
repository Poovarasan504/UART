void setup() {
  // put your setup code here, to run once:
  volatile char *dir_d=0x2A;
  volatile char *in_d=0x29;
  volatile char *dir_b=0x24;
  volatile char *out_b=0x25;
  *dir_d=0x00;
  *dir_b=0xff;
  volatile long j=0,i;
  char x,data=0;
  while(1){
   x=*in_d;
   if(x==1){
    for(i=0;i<15000;i++);
    for(j=0;j<8;j++){
       x=*in_d;
       if(x==0x01) data|=(1<<j);
       else data&= ~(1<<j);
        for(i=0;i<10000;i++);
       
    }
    *out_b=data;
    for(i=0;i<10000;i++);
    *out_b=0;
    
   }

      }}
  



void loop() {
  // put your main code here, to run repeatedly:

}
