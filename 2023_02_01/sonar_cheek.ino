#include <NewPing.h>
#define SONAR_NUM 3
#define MAX_DISTANCE 150 //cm
#define DEBUG 1 //1하면 출력을 할 것이다.

#define MAX_DISTANCE 250
float R_Sonar_Distance = 0.0;
float L_Sonar_Distance = 0.0;
float F_Sonar_Distance = 0.0;

float UlteasonicSeneorData[SONAR_NUM];

NewPing sonar[SONAR_NUM] ={
  NewPing(48, 50, MAX_DISTANCE), //앞
  NewPing(42, 44, MAX_DISTANCE),// 오른쪽
  NewPing(9, 10, MAX_DISTANCE) // 왼쪽
  };


void read_sonar_sensor(void)
{

   F_Sonar_Distance = sonar[0].ping_cm() * 10;
   R_Sonar_Distance = sonar[1].ping_cm() * 10;
   L_Sonar_Distance = sonar[2].ping_cm() * 10;

   if(F_Sonar_Distance == 0) F_Sonar_Distance = MAX_DISTANCE *10.0;
   if(R_Sonar_Distance == 0) R_Sonar_Distance = MAX_DISTANCE *10.0;
    if(L_Sonar_Distance == 0) L_Sonar_Distance = MAX_DISTANCE *10.0;
  
}

void serial_com(void)
{
  if(DEBUG != 1) 
  {
      return;
  }
  
  Serial.print("F_Sonar : ");
  Serial.print(F_Sonar_Distance);   //1인 경우에는 다음과 같이 sonar 값을 출략한다. 
  Serial.print(" ");
    
  Serial.print("R_Sonar : ");
  Serial.print(R_Sonar_Distance);
  Serial.print(" ");

  Serial.print("L_Sonar : ");
  Serial.println(L_Sonar_Distance);   //1인 경우에는 다음과 같이 sonar 값을 출략한다. 
  Serial.print(" ");
  
}

void setup() {
  
  //(MOTOR_DIR, OUTPUT);
  //pinMode(MOTOR_PWM, OUTPUT);

  //Steeringservo.attach(RC_SERVO_PIN);  // 8번 핀을 서보로 사용하겠다.
  //Steeringservo.write(NEURAL_ANGLE);  //초기는 90도 중립을, 0~90도로 움직인다.
  
  Serial.begin(115200);

}

////////////////////////////////////////////////////////////////////////////////

void loop() {

  read_sonar_sensor();
  serial_com();
  delay(100);

}
