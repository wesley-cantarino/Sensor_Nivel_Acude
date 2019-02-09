## Relé controlado por time usando arduino.

### Objetivo
  Controlar cargas de corrente alternada (de até 10A) por time (tempo). Ou seja, O projeto final terá a função de um temporizador e ao mesmo tempo, que tenha um custo de fabricação barato.

### Motivação
  Esse projeto nasceu como uma solução de um problema prático. Onde temos um açude (um "buraco") onde é feito a criação de peixes e um rio. O rio está abaixo do açude de forma que a água não suba de forma natural até o açude. O circuito que irá controlar a bomba d´água terá que ligar a bomba, aguardar algum tempo e depois desliga lá por certo tempo e essa atividade será ciclica.

### Materiais usados
  1. Arduino pro mini
      * O uso de um arduino pro mini em vez de um nano ou uno é justamente por causa do preço. o arduino pro mini custa em média R$13.

      * ![Aquela imagem top aqui](https://user-images.githubusercontent.com/32984446/52522518-88d18280-2c6d-11e9-897c-c180881201a2.jpeg) esse aqui, eu mesmo que soldei mais no projeto eu usei outro que não tinha sido soldado.

  2. Relé
      * No meu caso, eu usei um que é ativado com 5V. A maioria que se encontra no mercado são de 12V ativação.

      * ![Aquela imagem top aqui](https://user-images.githubusercontent.com/32984446/52522587-6a1fbb80-2c6e-11e9-8320-eb51edb1d92c.jpeg)

  3. Fonte com saída 5V
      * ![Aquela imagem top aqui](https://user-images.githubusercontent.com/32984446/52522632-ffbb4b00-2c6e-11e9-910f-0f624500e4bb.jpeg)

  4. Led e resistor
      * Usei Led amarelo e um resistor de 320 ohms para indicar que o relé está ligado.


  | Produto | Preço em R$ |
  | ------  | ----- |
  | Arduino pro mini | 13 |
  | Relé | 3 |
  | Fonte 5V | 10 |
  | Led e resistor | <0.20 |
  |total: | R$26.2|


## Começando o projeto

### Oque é arduino pro mini e como programa-lo?
  O arduino pro mini é "1/3" arduino nano. Ele só tem o micro controlador em si (o ATmega328P de 5V).

  ![foto do arduino nano]()

  Para programa-lo vamor usar essa pecinha (também chamada de conversor serial):
  ![foto da pecinha](https://user-images.githubusercontent.com/32984446/52522678-af90b880-2c6f-11e9-8b1f-172cfc2e9ce7.jpeg)
  Se você repara, verá que ela tem o mesmo chip serial.

  Fazedo a ligação
  | Conversor serial | Arduino |
  | - | -|
  | Vcc 5V | Vcc |
  | GND | GND |
  | Tx | Rx |
  | Rx | Tx |

  Para fins de teste, vamos carregar o código blick modificado.

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
  delay(50);   // wait for a second

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

Se tudo deu certo. O led da placa ficará piscando e imprimindo no munitor serial "I'm alive hahahaha  cont: " mais a variavel cont que vai se somando.

## Como usar o relé ?
