## Relé controlado por time usando arduino.

### Objetivo
  Controlar cargas de corrente alternada (de até 10A) por time (tempo). Ou seja, O projeto final terá a função de um temporizador e ao mesmo tempo, que tenha um custo de fabricação barato.

### Motivação
  Esse projeto nasceu como uma solução de um problema prático. Onde temos um açude (um "buraco" cheio d'água) onde é feito a criação de peixes e um pequeno rio. O rio está abaixo do açude de forma que a água não vá de forma natural até o açude. O circuito que irá controlar a bomba d´água terá que ligar a bomba, aguardar algum tempo e depois desliga-lá por certo tempo e essa atividade será ciclica.

### Materiais usados
  1. Arduino pro mini
      * O uso de um arduino pro mini em vez de um nano ou uno é justamente por causa do preço. o arduino pro mini custa em média R$13.

      * Esse aqui, eu mesmo que soldei mais no projeto eu usei outro que não tinha sido soldado.![Aquela imagem top aqui](https://user-images.githubusercontent.com/32984446/52522518-88d18280-2c6d-11e9-897c-c180881201a2.jpeg)

  2. Relé
      * No meu caso, eu usei um que é ativado com 5V. A maioria que se encontra no mercado são de 12V ativação.

      * ![Aquela imagem top aqui](https://user-images.githubusercontent.com/32984446/52522587-6a1fbb80-2c6e-11e9-8320-eb51edb1d92c.jpeg)

  3. Fonte com saída 5V
      * Essa eu retirei de um carregador de celular ![Aquela imagem top aqui](https://user-images.githubusercontent.com/32984446/52522632-ffbb4b00-2c6e-11e9-910f-0f624500e4bb.jpeg)

  4. Led e resistor
      * Usei Led amarelo e um resistor de 320 ohms para indicar que o relé está ligado.


  | Produto | Preço em R$ |
  | ------  | ----- |
  | Arduino pro mini | 13 |
  | Relé | 3 |
  | Fonte 5V | 10 |
  | Led e resistor | <0.20 |
  |total: | R$26.2|


## Começando o projeto ...

### Oque é arduino pro mini e como programa-lo?
  O arduino pro mini é "1/3" arduino nano. Ele só tem o micro controlador em si (o ATmega328P de 5V).

  ![foto do arduino nano]()

  Para programa-lo vamor usar essa pecinha (também chamada de conversor serial):
  ![foto da pecinha](https://user-images.githubusercontent.com/32984446/52522678-af90b880-2c6f-11e9-8b1f-172cfc2e9ce7.jpeg)
  Se você repara, verá que ela tem o mesmo chip serial do Arduino.

  Fazedo a ligação. Atenção pois o Tx do conversor é o Rx do Arduino e vice-versa :).

  | Conversor serial | Arduino |
  | - | -|
  | Vcc 5V | Vcc |
  | GND | GND |
  | Tx | Rx |
  | Rx | Tx |

  Para fins de teste, vamos carregar o código blick (aquele que pisca o led da placa Arduino) modificado.

  ``` c++
  int cont = 1;

  void setup()
  {
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
  }

  void loop()
  {
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(100);                       
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);     

    digitalWrite(LED_BUILTIN, HIGH);   
    delay(100);                      
    digitalWrite(LED_BUILTIN, LOW);   
    delay(50);

    digitalWrite(LED_BUILTIN, HIGH);  
    delay(50);                      
    digitalWrite(LED_BUILTIN, LOW);    
    delay(500);

    Serial.print("I'm alive hahahaha");
    Serial.print("  cont: ");
    Serial.println(cont);
    cont++;
  }
```

Obs: no caso desse conversor serial, tem que apertar o botão resete do arduino para carregar o código.

Se tudo deu certo. O led da placa ficará piscando e imprimindo no monitor serial "I'm alive hahahaha  cont: " mais a variavel cont que vai se somando.

## Como usar o relé ?

![foto do relé](https://user-images.githubusercontent.com/32984446/52522678-af90b88.jpeg)

Onde:
  * A e B é os pontos onde vamos energizar.
  * COM é o ponto da carga em comum. Onde vamos ligar o fio fase 127Vac.
  * NA é normalmente aberto. Se os pontos A e B não tiver energia não terá continuidade entre pontos NA e COM.
  * NF é normalmente fechado. Se os pontos A e b não tiver energia terá continuidade entre os pontos NF e COM.

Olhando na foto. Energizando os ponto A e B, o ponto normalmente aberto (NA) vai ficar fechado.

Obs: Dependendo do relé, tem que montar um circuito para tirar ruído. Bom, eu ainda estou estudando sobre isso...

## Juntando tudo

Ok. O correto fazer uma placa (PCB) e juntar todos os componentes. Mas... eu não tenho acesso a cnc (ainda está no papel a construção de uma). Então, vou juntar em uma placa genérica e soldar alguns pontos.

Fazendo essa ligação:
* ![foto do projeto no cad]()

Na prática ficou assim:
* ![foto do projeto]()

## Packages (itens adcionais)
