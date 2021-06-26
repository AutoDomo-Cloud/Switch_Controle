//Programa: Lighting and Relay Module
//Autor: Elton de Sousa e Silva
//Email: admin@autodomo.io
//Versão 1.1
 
#include <ESP8266WiFi.h>        // Import the Library ESP8266WiFi
#include <PubSubClient.h>       // Import the Library PubSubClient
 

#define TOPIC_SUBSCRIBE1 "/autodomo/User0000083/01AAF39067D2/light/value"    //Put here the MQTT topic 1 of receiving Autodomo Server information
#define TOPIC_SUBSCRIBE2 "/autodomo/User0000083/01AA746A552B/light/value"    //Put here the MQTT topic 2 of receiving Autodomo Server information
#define TOPIC_SUBSCRIBE3 "/autodomo/User0000083/01AA9F137A38/light/value"    //Put here the MQTT topic 3 of receiving Autodomo Server information
#define TOPIC_SUBSCRIBE4 "/autodomo/User0000083/01AA9F137A38/light/value"    //Put here the MQTT topic 3 of receiving Autodomo Server information

#define TOPIC_PUBLISH1   "/autodomo/User0000083/01AAF39067D2/light/state"    //Put here the MQTT Topic of sending information to the Autodomo Server
#define TOPIC_PUBLISH2   "/autodomo/User0000083/01AA746A552B/light/state"    //Put here the MQTT Topic of sending information to the Autodomo Server
#define TOPIC_PUBLISH3   "/autodomo/User0000083/01AA9F137A38/light/state"    //Put here the MQTT Topic of sending information to the Autodomo Server
#define TOPIC_PUBLISH4   "/autodomo/User0000083/01AA9F137A38/light/state"    //Put here the MQTT Topic of sending information to the Autodomo Server

#define ID_MQTT  "01AAF39067D2"     //MQTT ID For identification (Required))

#define Relay1   12                  //Relay 1 output change according to your board
#define Relay2   5                   //Relay 2 output change according to your board
#define Relay3   4                   //Relay 3 output change according to your board
#define Relay4   15                  //Relay 4 output change according to your board


#define S1   0                   //Relay 1 output change according to your board
#define S2   9                   //Relay 2 output change according to your board
#define S3   10                  //Relay 3 output change according to your board
#define S4   14                  //Relay 4 output change according to your board


unsigned long currentMillis;
unsigned long tempo_tecla1_anterior_Millis = 0;
unsigned long tempo_tecla2_anterior_Millis = 0;
unsigned long tempo_tecla3_anterior_Millis = 0;
unsigned long tempo_tecla4_anterior_Millis = 0;
 
// WIFI
const char* SSID = "hackeandoSuaInternet"; // SSID  name of the WI-FI network you want to connect
const char* PASSWORD = "L@isK@rl@D@lil@"; // Password of the WI-FI network you want to connect
  
// MQTT
const char* BROKER_MQTT = "mqtt.autodomo.io"; //Autodomo MQTT broker URL not change
int BROKER_PORT = 1883; // MQTT Broker port. not change.
const char* USER_MQTT = "User0000083";    // MQTT User (Search Autodomo.io Site)
const char* PASSWORD_MQTT = "za6lbl85";    // MQTT Password (Search Autodomo.io Website)
 
 
//Variáveis e objetos globais
WiFiClient espClient; // Cria o objeto espClient
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT passando o objeto espClient
bool EstadoSaida1 = false;  //variável que armazena o estado atual da saída
bool EstadoSaida2 = false;  //variável que armazena o estado atual da saída
bool EstadoSaida3 = false;  //variável que armazena o estado atual da saída
bool EstadoSaida4 = false;  //variável que armazena o estado atual da saída
  
//Prototypes
void initSerial();
void initWiFi();
void initMQTT();
void reconectWiFi(); 
void mqtt_callback(char* topic, byte* payload, unsigned int length);
void VerificaConexoesWiFIEMQTT(void);
void InitOutput(void);
 
/* 
 *  Implementações das funções
 */
void setup() 
{
    //inicializações:
    InitOutput();
    initSerial();
    initWiFi();
    initMQTT();
}
  



//programa principal
void loop() 
{   
    //garante funcionamento das conexões WiFi e ao broker MQTT
    VerificaConexoesWiFIEMQTT();
 
    //envia o status de todos os outputs para o Broker no protocolo esperado
   // EnviaEstadoOutputMQTT();
 
    //keep-alive da comunicação com broker MQTT
    MQTT.loop();
    checkSwitch();
}
