int R[7][7]=
{
  {-1,0,0,-1,-1,-1,-1},
  {0,-1,-1,0,-1,-1,-1},
  {0,-1,-1,0,-1,-1,100},
  {-1,0,0,-1,0,-1,-1},
  {-1,-1,-1,0,-1,0,-1},
  {-1,-1,-1,-1,0,-1,100},
  {-1,-1,-1,-1,-1,-1,-1}
};
int Q [7][7] = 
 {
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0}
};

int odalar[7]={2,5,3,6,7,8,4};
int AnlikOda=0;
int HedefOda=6;
int hareket=0;
int RandomSayi=0;
int MaksimumSayi=0;
int n=0;
int test_index=0;
int sonuc;
void ledleri_kapa()
{
  for(int i=0; i<7; i++)
  {
  digitalWrite(odalar[i],0);
  }
}
void oda_test(int led_pin)
{
  switch(led_pin)
  {
    case 0:
    ledleri_kapa();
    digitalWrite(odalar[0],1);
    break;
    case 1:
    ledleri_kapa();
    digitalWrite(odalar[1],1);
    break;
    case 2:
    ledleri_kapa();
    digitalWrite(odalar[2],1);
    break;
    case 3:
    ledleri_kapa();
    digitalWrite(odalar[3],1);
    break;
    case 4:
    ledleri_kapa();
    digitalWrite(odalar[4],1);
    break;
    case 5:
    ledleri_kapa();
    digitalWrite(odalar[5],1);
    break;
    case 6:
    ledleri_kapa();
    digitalWrite(odalar[6],1);
    break;
    
    
  }
}
void setup() {
  for(int i=0; i<7; i++)
  { 
    pinMode(odalar[i],OUTPUT);
  }
  Serial.begin(9600);
  
  

}

void loop() {
  while(n<6) 
  {
    while(AnlikOda != HedefOda)
    {
      
      oda_test(AnlikOda);
      RandomSayi=random(0,7);
      while(R[AnlikOda][RandomSayi]<0){
        RandomSayi=random(0,7);
      }
      hareket=RandomSayi;
      MaksimumSayi=Q[hareket][0];
      for(int i=1; i<7; i++)
      {
        if(Q[hareket][i]>MaksimumSayi)
        {
        MaksimumSayi=Q[hareket][i]; }
      }
     Q[AnlikOda][hareket]=R[AnlikOda][hareket]+0.8*MaksimumSayi;
     
     AnlikOda=hareket;
     delay(400);
    }
    oda_test(HedefOda);
    delay(400);
    n++;
    AnlikOda=0;
   
  }/*
   AnlikOda=0;
   int i;
   while(AnlikOda != HedefOda)
   {
    oda_test(AnlikOda);
    MaksimumSayi=weights[AnlikOda][0];
    test_index=0;
    for( i=1; i<7; i++)
    {
      if(weights[AnlikOda][i]>MaksimumSayi)
       {
        MaksimumSayi=weights[AnlikOda][i];
        test_index=i;
        int sum=0;
        sum += i;
        
       }
    }
    AnlikOda=test_index;
    
   }
   oda_test(HedefOda); */
     for(int i=0; i<7; i++)
    { Serial.print("\n");
      for(int y=0; y<7; y++)
      {
        Serial.print(Q[i][y]);
        Serial.print("\t");
        
      }
    }
    delay(10000);
    
  }
  

