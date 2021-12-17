int led_pin = 13;
int led_interval=400;
int sensor1_val=0;
int sensor2_val=0;
int state=-1;
bool read_s1=false;
bool read_s2=false;

void get_num(char a)
{
    if(a=='d')
    {
      state=0;
    }
    else if(a=='u')
    {
      state=1;
    }
    else if(a=='b')
    {
      state=2;
    }
        else if(a=='1')
    {
      read_s1=true;
    }
        else if(a=='2')
    {
      read_s2=true;
    }
}

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}


void loop() {

  while(Serial.available()>0)
  {
    char a=Serial.read();
    get_num(a);
  }
  if(state==0 or state==1)
  {
    digitalWrite(led_pin,state);
  }
  else if(state==2)
  {
    digitalWrite(led_pin,(millis()/led_interval)%2);
  }
  if(read_s1)
  {
    sensor1_val=analogRead(A0);
    Serial.println(sensor1_val);
    read_s1=true;
  }
  if(read_s2)
  {
    sensor2_val=analogRead(A1);
    Serial.println(sensor2_val);
    read_s2=false;
  }
}
