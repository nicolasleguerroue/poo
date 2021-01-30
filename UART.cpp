/*!
 * \file UART.cpp
 * \brief Gestionnaire UART pour carte Arduino [END]
 * \author Nicolas LE GUERROUE
 * \version 1.0
 */

#include "Arduino.h"
#include "UART.h"
#include "SoftwareSerial.h"


/** \namespace utils
 * Espace de nom pour les composants Arduino
 */



namespace utils {

  /*! \class UART
   * \brief Classe permettant de gérer une liaison série
   *
   *  La classe gère deux périphériques
   */
  class UART {

   private:

   int cout=0;  /*!< Compteur interne*/

   public:

    /*!
     *  \brief Constructeur de classe
     *
     *  \param rx : broche de réception
     *  \param tx : broche d'émission
     *  \return void
     */

	UART(int rx, int tx)
   	: _serial(rx, tx)
	{
	
	}

   /*!
     *  \brief Initialise la communication
     *
     *  \return void
     */

void begin(unsigned long bauds) {
	_serial.begin(bauds);
}


    /*!
     *  \brief Lecture des données
     *
     *  \return string
     */

String read() {

 String message="";

if(_serial.available()>0) {
 while(_serial.available()>0) {

	c = _serial.read();
	message = message + c;
	delay(2);
	}//fin while

return(message);
}

}//fin lecture


    /*!
     *  \brief Lecture des données avec attente des données
     *
     *  \return string
     */

String read(uint8_t position) {

String message="";

if(position==LOCKED) {

 do {delayMicroseconds(10);}
 while(_serial.available()==0); 
 
  while(_serial.available()>0)
  
  {
	c = _serial.read();
	message = message + c;
	delay(2);
	}//fin while

return(message);

}//fin do while
}//fin lecture



    /*!
     *  \brief Envoi des données sous forme de chaine
     *
     *  \param message : Message à envoyer
     *  \return void
     */

void send(String message) {

 	_serial.println(message);

}//fin send

    /*!
     *  \brief Envoi des données sous forme d'entier
	 * 
     *  \param message : Message à envoyer
     *  \return void
     */

void send(int message) {

 	_serial.println(message);

}//fin send

//FIN UART

  }

}
