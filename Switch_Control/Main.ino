//Função: envia ao Broker o estado atual do output 
//Parâmetros: int numberOut
//Retorno: nenhum
void EnviaEstadoOutputMQTT(int numberOut)
{
  if(numberOut == 1){
     if (!EstadoSaida1)
      MQTT.publish(TOPIC_PUBLISH1, "0");
 
     if (EstadoSaida1)
      MQTT.publish(TOPIC_PUBLISH1, "1");
      
  }else if(numberOut == 2){
     if (!EstadoSaida2)
      MQTT.publish(TOPIC_PUBLISH2, "0");
 
    if (EstadoSaida2)
      MQTT.publish(TOPIC_PUBLISH2, "1");
      
  }else if(numberOut == 3){
     if (!EstadoSaida3)
      MQTT.publish(TOPIC_PUBLISH3, "0");
 
    if (EstadoSaida3)
      MQTT.publish(TOPIC_PUBLISH3, "1");
      
  }else if(numberOut == 4){
     if (!EstadoSaida4)
      MQTT.publish(TOPIC_PUBLISH4, "0");
 
    if (EstadoSaida4)
      MQTT.publish(TOPIC_PUBLISH4, "1");
      
  }  


}


void checkSwitch()
{

  if (!digitalRead(S1))
  {
    bool stateRelay = false;
    
    if (millis() - tempo_tecla1_anterior_Millis >= 250)
    {
      tempo_tecla1_anterior_Millis = millis();
      stateRelay = !digitalRead(Relay1);
      digitalWrite(Relay1, stateRelay);  // invert o valor do rele"
      EstadoSaida1 = stateRelay;
      EnviaEstadoOutputMQTT(1);
    }
      
   }else if (!digitalRead(S2)){
    
      bool stateRelay = false;
      
      if (millis() - tempo_tecla2_anterior_Millis >= 250)
      {
        tempo_tecla2_anterior_Millis = millis();
        stateRelay = !digitalRead(Relay2);
        digitalWrite(Relay2, stateRelay);  // invert o valor do rele"
        EstadoSaida2 = stateRelay;
        EnviaEstadoOutputMQTT(2);
       }

  }else if (!digitalRead(S3)){
    
      bool stateRelay = false;
      
      if (millis() - tempo_tecla3_anterior_Millis >= 250)
      {
        tempo_tecla3_anterior_Millis = millis();
        stateRelay = !digitalRead(Relay3);
        digitalWrite(Relay3, stateRelay);  // invert o valor do rele"
        EstadoSaida3 = stateRelay;
        EnviaEstadoOutputMQTT(3);
      }
  }else if (!digitalRead(S4)){
    
      bool stateRelay = false;
      
      if (millis() - tempo_tecla4_anterior_Millis >= 250)
      {
        tempo_tecla4_anterior_Millis = millis();
        stateRelay = !digitalRead(Relay4);
        digitalWrite(Relay4, stateRelay);  // invert o valor do rele"
        EstadoSaida4 = stateRelay;
        EnviaEstadoOutputMQTT(4);
      }
  }

  
}
