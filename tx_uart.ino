void setup() {
  // put your setup code here, to run once:
  volatile char *dir_d=0x2A;
  volatile char *in_d=0x29;
  volatile char *dir_b=0x24;
  volatile char *out_b=0x25;
  *dir_d=0x00;
  *dir_b=0xff;
  volatile long j,i;
  char x,data1=0x0f,data2=0xf0;
  while(1){
    x=*in_d;
    while(x==0){
     x=*in_d;
     if(x==0x01){
      *out_b=0x01; //start bit
       for(i=0;i<10000;i++);
       for(j=0;j<8;j++){
       *out_b=(data1>>j)&0x01;
       for(i=0;i<10000;i++);}
       *out_b=0; //stop bit
       
        }
       else if(x==0x02){
        *out_b=0x01; //start bit
       for(i=0;i<10000;i++);
       for(j=0;j<8;j++){
       *out_b=(data2>>j)&0x01;
       for(i=0;i<10000;i++);}
       *out_b=0; //stop bit
       
      }}
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
