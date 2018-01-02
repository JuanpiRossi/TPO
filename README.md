# TPO

Manual de uso:

-cargar las preguntas y respuestas en los campos, asegurandose de apretar gaurdar al completar todos los campos
-(opcional) previsualizar para ver si todo lo que cargo esta bien
-apretar empezar juego cuando cargo las preguntas


Manual de mensajes series:

-composicion del mensaje (separo los caracteres con''):
  '<' 'Cantidad de caracteres de mensaje' 'id' 'accion1' 'accion2' "mensaje" 'xor' '>'
-acciones: P 1-7	  pregunta
		       A 1-7	  respuesta A
		       B 1-7	  respuesta B
		       C 1-7	  respuesta C
		       D 1-7	  respuesta D
		       X X	    Cantidad de preguntas
		       N 1-7	  Cantidad de respuestas
		       C C	    mensaje para pedir confirmacion
           r 1-7	  reenvio pregunta
           a 1-7	  reenvio respuesta A
           b 1-7	  reenvio respuesta B
           c 1-7	  reenvio respuesta C
           d 1-7	  reenvio respuesta D
           E E	    Empieza el juego
           F F	    Fin del juego

           R O     	respuesta de esclavo (todo ok)
           R M	    respuesta de esclavo (con error)
           R F	    respuesta de esclavo (fin del juego)
           
           
Orden de mensajes serie:
  (en el ejemplo se contemple 2 preguntas, la primera con 3 respuestas y la segunda con 2)
  -Ni bien empretas empezar juego se envian las preguntas y respuestas:
    -primero se enviar la cantidad de preguntas, ejemplo: '<'+1+255+'X'+'X'+2+2+'>'
    -despues se envian las preguntas y respuestas, ejemplo: '<'+3+255+'P'+1+'1'+'2'+'3'+48+'>'    //pregunta1 = 123
                                                            '<'+1+255+'N'+1+3+3+'>'               //cantidad de respuestas1 = 3
                                                            '<'+3+255+'A'+1+'A'+'A'+'A'+65+'>'    //respuestaA1 = AAA
                                                            '<'+3+255+'B'+1+'B'+'B'+'B'+66+'>'    //respuestaB1 = BBB
                                                            '<'+3+255+'C'+1+'C'+'C'+'C'+67+'>'    //respuestaC1 = CCC
                                                            '<'+3+255+'P'+2+'4'+'5'+'6'+55+'>'    //pregunta2 = 456
                                                            '<'+1+255+'N'+2+2+2+'>'               //cantidad de respuestas2 = 2
                                                            '<'+3+255+'A'+2+'D'+'D'+'D'+68+'>'    //respuestaD1 = DDD
                                                            '<'+3+255+'B'+2+'E'+'E'+'E'+69+'>'    //respuestaE1 = EEE
    -Despues se envian los mensajes de confirmacion a cada id (5 en total), ejemplo: '<'+1+1+'C'+'C'+1+1+'>' //pide confirmacion al id=1, el mensaje puede ser cualquier
                                                                                     '<'+1+2+'C'+'C'+1+1+'>' //pide confirmacion al id=2, el mensaje puede ser cualquier
                                                                                     '<'+1+3+'C'+'C'+1+1+'>' //pide confirmacion al id=3, el mensaje puede ser cualquier
                                                                                     '<'+1+4+'C'+'C'+1+1+'>' //pide confirmacion al id=4, el mensaje puede ser cualquier
                                                                                     '<'+1+5+'C'+'C'+1+1+'>' //pide confirmacion al id=5, el mensaje puede ser cualquier
    -Entre cada mensaje se espera que los esclavos respondan si recibieron todo bien o tuvieron algun error:
      -En caso de estar todo bien responde lo siguiente, ejemplo: '<'+1+1+'R'+'O'+1+1+'>' //Respuesta de id=1 de todos los mensajes bien recibidos, el mensaje puede ser cualquier
                                                                  '<'+1+2+'R'+'O'+1+1+'>' //Respuesta de id=2 de todos los mensajes bien recibidos, el mensaje puede ser cualquier
                                                                  '<'+1+3+'R'+'O'+1+1+'>' //Respuesta de id=3 de todos los mensajes bien recibidos, el mensaje puede ser cualquier
                                                                  '<'+1+4+'R'+'O'+1+1+'>' //Respuesta de id=4 de todos los mensajes bien recibidos, el mensaje puede ser cualquier
                                                                  '<'+1+5+'R'+'O'+1+1+'>' //Respuesta de id=5 de todos los mensajes bien recibidos, el mensaje puede ser cualquier
      -En caso de tener algun problemas debe usar la accion "RM", ejemplo: '<'+8+2+'R'+'M'+'P'+1+'A'+1+'C'+1+'P'+2+1+'>' // Respuesta de id=2, pidiendo reenviar la pregunta 1, respuesta A1, C1 y pregunta 2
                                                                           '<'+2+3+'R'+'M'+'A'+2+67+1+'>' // Respuesta de id=3, pidiendo reenviar la respuesta A2
      -Luego de esto se reenvia TODOS los campos pedidos por todos los esclavos, ejemplo: '<'+3+255+'p'+1+'1'+'2'+'3'+48+'>'    //reenvio de pregunta1
                                                                                          '<'+3+255+'a'+1+'A'+'A'+'A'+65+'>'    //reenvio de respuestaA1
                                                                                          '<'+3+255+'c'+1+'C'+'C'+'C'+67+'>'    //reenvio de respuestaC1
                                                                                          '<'+3+255+'p'+2+'4'+'5'+'6'+55+'>'    //reenvio de pregunta2
                                                                                          '<'+3+255+'a'+2+'D'+'D'+'D'+68+'>'    //reenvio de respuestaD1
    -Se va a reenviar hasta 3 veces el mensaje de confirmacion en caso de ser necesario, en caso de no recibir mensaje con accion "RO" en esas 3 posibilidades se considera que el esclavo esta muerto
    -Cuando se termina el proceso de confirmacion se envia el mensaje de inicio de juego, ejemplo: '<'+1+255+'E'+'E'+15+15+'>' //El mensaje es igual a la cantidad de segundos que se van a jugar
    -Se espera que durante el juego a medida que van terminado de responder la aplicacion resiva las respuestas
      -la composicion de la respuesta es: '<'+21+'id'+'P'+1+'A-D'+'P'+2+'A-D'+'P'+3+'A-D'+'P'+4+'A-D'+'P'+5+'A-D'+'P'+6+'A-D'+'P'+7+'A-D'+'xor'+'>'
      -Ejemplo: '<'+21+'1'+'P'+1+'C'+'P'+2+'B'+'P'+3+#+'P'+4+#+'P'+5+#+'P'+6+#+'P'+7+#+114+'>' //el id=1 respondio en la primer pregunta C y en el segunda B, si la pregunta no existe se puede poner cualquier valor en la respuesta (en este caso puse #)
    -Los esclavos tienen tiempo de responder hasta que termina el tiempo, donde la aplicacion manda su mensaje de fin, ejemplo: '<'+1+255+'F'+'F'+1+1+'>'
    -En este momento termina el juego y no se envian mas mensajes ni se contempla recibir mas mensajes
           
           
           
   



