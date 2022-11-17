// #include "mbed.h"
// #include "TS_DISCO_F746NG.h"
// #include "LCD_DISCO_F746NG.h"
// #include "EthernetInterface.h"
// #include <string>

// #define BTN_R1_X 60 //coordenada X do botão relé 1
// #define BTN_R1_Y 130 //coordenada Y do botão relé 1

// #define BTN_WIDTH  150 //largura do botão dos relés
// #define BTN_HEIGHT 75 //altura do botão dos relés

// #define BTN_R2_X 50 + (BTN_R1_X + BTN_WIDTH) //coordenada X do botão relé 2
// #define BTN_R2_Y 130 //coordenada Y do botão relé 1

// LCD_DISCO_F746NG lcd; //objeto que controla o display
// TS_DISCO_F746NG ts;  //objeto que controla o touch do display

// TCPSocket *clt_sock; //ponteiro para um socket TCP

// //variáveis de controle de estado dos relés
// bool btnRelay1 = false;
// bool btnRelay2 = false;

// /* PROTÓTIPO DAS FUNÇÕES */
// //desenha um um botão na tela com uma escrita no meio
// void drawButton(int x, int y, int width, int height, uint32_t color, char* title);
// //verifica se ocorreu um toque na tela
// void verifyTouch(int x, int y);
// //verifica se o toque foi em algum dos botões
// bool verifyTouchButton(int x, int y, int rectX, int rectY);
// //envia um pacote de comandos para o client
// bool sendPacket(char* packet);
// //escreve na tela o status da conexão (client conectado ou desconectado)
// void writeStatus(char* status, uint32_t color);


// int main()
// {
//     TS_StateTypeDef TS_State; //estado do touch
//     uint8_t status;

//     status = ts.Init(lcd.GetXSize(), lcd.GetYSize()); //inicializa o touch na tela toda
//     //se deu erro ao inicializar -> mensagem de falha e pára a execução do programa 
//     if (status != TS_OK) {
//         lcd.Clear(LCD_COLOR_RED);
//         lcd.SetBackColor(LCD_COLOR_RED);
//         lcd.SetTextColor(LCD_COLOR_WHITE);
//         lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN INIT FAIL", CENTER_MODE);
//         ThisThread::sleep_for(2);
//         return 0;
//     }

//     lcd.Clear(LCD_COLOR_BLUE); //limpa a tela e pinta de azul
//     lcd.SetBackColor(LCD_COLOR_BLUE); //cor de fundo de texto
//     lcd.SetTextColor(LCD_COLOR_YELLOW); //cor do texto
//     lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN INIT OK", CENTER_MODE);


//     ThisThread::sleep_for(1); //aguarda um segundo
//     lcd.Clear(LCD_COLOR_BLUE); //limpa a tela
//     lcd.SetTextColor(LCD_COLOR_WHITE); //seta cor do texto
//     lcd.SetFont(&Font24); //seta tamanho da fonte
//     lcd.DisplayStringAt(0, LINE(1), (uint8_t *)"BaseStation", CENTER_MODE);

//     lcd.DisplayStringAt(BTN_R1_X, LINE(4), (uint8_t *)"RELAY 1", LEFT_MODE);
//     lcd.DisplayStringAt(BTN_R2_X, LINE(4), (uint8_t *)"RELAY 2", LEFT_MODE);

//     //cria os botões
//     drawButton(BTN_R1_X, BTN_R1_Y, BTN_WIDTH, BTN_HEIGHT, LCD_COLOR_RED, "OFF");
//     drawButton(BTN_R2_X, BTN_R2_Y, BTN_WIDTH, BTN_HEIGHT, LCD_COLOR_RED, "OFF");

//     //objeto que controla a rede ethernet
//     EthernetInterface eth;
//     eth.connect(); //conecta à rede

//     lcd.SetBackColor(LCD_COLOR_BLUE);
//     lcd.SetFont(&Font8);

//     while(1){}
     
// }

// //desenha um um botão na tela com uma escrita no meio
// void drawButton(int x, int y, int width, int height, uint32_t color, char* title)
// {
//     lcd.SetFont(&Font24);
//     lcd.SetTextColor(color);
//     lcd.SetBackColor(color);
//     lcd.FillRect(x, y, width, height);
//     lcd.SetTextColor(LCD_COLOR_WHITE);
//     uint8_t text[30];
//     sprintf((char*)text, "%s", title);
//     lcd.DisplayStringAt(x+50, y+(height/2)-10, (uint8_t *)&text, LEFT_MODE);
// }

// //verifica se ocorreu um toque na tela
// void verifyTouch(int x, int y)
// {
//     bool response = false; //guarda o status do envio da mensagem para o client
//     //verifica se tocou no botão do relé 1
//     if( verifyTouchButton(x, y, BTN_R1_X, BTN_R1_Y) ) {
//         char* text;
//         uint32_t color;
//         //se o relé está ligado então desliga
//         if(btnRelay1) {
//             text = "OFF";
//             color = LCD_COLOR_RED;
//             response = sendPacket("#R1|0"); //envia comando para desligar o relé
//         } else {
//             //se relé está desligado, então liga
//             text = "ON";
//             color = LCD_COLOR_GREEN;
//             response = sendPacket("#R1|1");//envia comando para ligar o relé
//         }
//         //se o envio foi confirmado
//         if(response) {
//             drawButton(BTN_R1_X, BTN_R1_Y, BTN_WIDTH, BTN_HEIGHT, color, text); //atualiza o botão
//             btnRelay1 = !btnRelay1;
//         }

//     }
//     //verifica se tocou no botão do relé 1 
//     else if( verifyTouchButton(x,y,BTN_R2_X,BTN_R2_Y) ) {
//         char* text;
//         uint32_t color;
//          //se o relé está ligado então desliga
//         if(btnRelay2) {
//             text = "OFF";
//             color = LCD_COLOR_RED;
//             response = sendPacket("#R2|0"); //envia comando para desligar o relé
//         } else {
//             //se relé está desligado, então liga
//             text = "ON";
//             color = LCD_COLOR_GREEN;
//             response = sendPacket("#R2|1");//envia comando para ligar o relé

//         }
//         //se o envio foi confirmado
//         if(response) {
//             drawButton(BTN_R2_X, BTN_R2_Y, BTN_WIDTH, BTN_HEIGHT, color, text);//atualiza o botão
//             btnRelay2 = !btnRelay2;
//         }
//     }
// }

// //verifica se o toque foi em algum dos botões
// bool verifyTouchButton(int x, int y, int rectX, int rectY)
// {
//     printf("tocou : %d,%d     %d,%d\n",x,y,rectX,rectY);
//     if( (x >= rectX) && (x <= rectX + BTN_WIDTH) )  {
//         if( (y >= rectY) && (y <= rectY + BTN_HEIGHT) )
//             return true;
//     }
//     return false;
// }

// //envia um pacote de comandos para o client
// bool sendPacket(char* packet)
// {
//     char buffer[256];
//     clt_sock->send(packet, strlen(packet)); //envia o comando
//     int n = clt_sock->recv(buffer, sizeof(buffer)); //aguarda confirmação
//     printf("N : %d\n",n);
//     //se não chegou bytes então client não recebeu o pacote
//     if (n <= 0) {
//         clt_sock->close(); //fecha o socket
//         clt_sock = NULL;
//         return false;
//     }
//     // print received message to terminal
//     buffer[n] = '\0';
//     printf("Received message from Client : %s\n",buffer);
//     return true;
// }

// //escreve na tela o status da conexão (client conectado ou desconectado)
// void writeStatus(char* status, uint32_t color)
// {
//     lcd.SetTextColor(color);
//     lcd.SetBackColor(LCD_COLOR_BLUE);
//     lcd.SetFont(&Font16);
//     lcd.ClearStringLine(16); //limpa a linha que escreveremos
//     uint8_t text[30];
//     sprintf((char*)text, "%s", status);
//     lcd.DisplayStringAtLine(16, (uint8_t *)&text);
// }




