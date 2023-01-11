#include <NewPing.h>

//3. VLF 로봇이 100mm 이동 했을 때 멈추게 하고
//그때의 각도를 측정하는 아두이노 프로그램을 작성하세요.(작동 동영상 포함)

#define  F_Sonar  8
#define  R_Sonar  10
#define  L_Sonar  11
#define MAX_DISTANCE 400
#define NUM_SONAR 3

#define  L_Sonar  11
#define  Left_Pin1  3
#define  Left_Pin2  2
#define  Right_Pin1  7
#define  Right_Pin2  4

#define Left 5
#define Right 6

NewPing F_sensor(F_Sonar,F_Sonar,MAX_DISTANCE);
NewPing L_sensor(L_Sonar,L_Sonar,MAX_DISTANCE);
NewPing R_sensor(R_Sonar,R_Sonar,MAX_DISTANCE);

float F_distance; 
float F_distance1,F_distance2,F_distance3;
float L_distance; 
float L_distance1,L_distance2,L_distance3;
float R_distance; 
float R_distance1,R_distance2,R_distance3;
float L_age, L_tan1, R_age, R_tan1;

NewPing sonar[3] =
{
  NewPing (8, 8, 500),
  NewPing (10, 10, 500),
  NewPing (11, 11, 500),
};


//모터 설정 1:전진, 2:후진, 3:우회전, 4:자회전, 5:정지///////////////////////////////////////////////////////
void motor_control(int direction, int spd){
  switch(direction){
    case 1: digitalWrite(Left_Pin1, HIGH);  
            digitalWrite(Left_Pin2, LOW);
            digitalWrite(Right_Pin1, HIGH);
            digitalWrite(Right_Pin2, LOW);
            analogWrite(Left, spd);
            analogWrite(Right, spd);
            break;
    
    case 2: digitalWrite(Left_Pin1, LOW);  
            digitalWrite(Left_Pin2, HIGH);
            digitalWrite(Right_Pin1, LOW);
            digitalWrite(Right_Pin2, HIGH);
            analogWrite(Left, spd);
            analogWrite(Right, spd);
            break;
            
    case 3: digitalWrite(Left_Pin1, LOW);
            digitalWrite(Left_Pin2, LOW);
            digitalWrite(Right_Pin1, LOW);
            digitalWrite(Right_Pin2, LOW);
            analogWrite(Left, 0);
            analogWrite(Right, 0);
            break;        
  }
}


//각도 구하는 함수////////////////////////////////////////////////////////////////////////////////////////
void Angle() { 
  
  F_distance1 = sonar[0].ping_cm()*10;
  R_distance1 = sonar[1].ping_cm()*10;
  L_distance1 = sonar[2].ping_cm()*10;
  motor_control(1, 80);
  
  F_distance2 = sonar[0].ping_cm()*10;
  F_distance3 = F_distance1 - F_distance2;
  R_distance2 = sonar[1].ping_cm()*10;  //과거의 R_distance 값 저장
  R_distance3 = R_distance1 - R_distance2;
  L_distance2 = sonar[2].ping_cm()*10;  //과거의 L_distance 값 저장
  L_distance3 = L_distance1 - L_distance2 ;

  //각도 구하기
  L_tan1 = L_distance3 / F_distance3;
  R_tan1 = R_distance3 / F_distance3;

  L_age = atan(L_tan1)*180/3.14;
  R_age = atan(R_tan1)*180/3.14; 

  /*
  Serial.print("L_Angle:");
  Serial.println(L_age);

  Serial.print("R_Angle:");
  Serial.println(R_age);
  
  
  Serial.print("F_Distance:");
  Serial.print(F_distance);

  Serial.print("R_Distance:");
  Serial.print(R_distance);

  Serial.print("L_Distance:");
  Serial.print(L_distance);
  Serial.print("mm\n"); */
  
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  pinMode(Left_Pin1, OUTPUT);
  pinMode(Left_Pin2, OUTPUT);
  pinMode(Right_Pin1, OUTPUT);
  pinMode(Right_Pin2, OUTPUT);
  Serial.begin(115200);
}

void loop(){
  
  float F_distance=(float)(F_sensor.ping())*10/US_ROUNDTRIP_CM;

  if(F_distance <= F_distance-100)
  {
      motor_control(5,0);
      Serial.print("   F : ");
      Serial.println(F_distance);
      }
      else
      {
        Angle();
      } 
}
