## Relé controlado por time usando arduino.

### Objetivo
  Controlar cargas de corrente alternada (de até 10A) por time (tempo). Ou seja, O projeto final terá a função de um temporizador e ao mesmo tempo, que tenha um custo de fabricação barato.

### Motivação
  Esse projeto nasceu como uma solução de um problema prático. Onde temos um açude (um "buraco" cheio d'água) onde é feito a criação de peixes e um pequeno rio. O rio está abaixo do açude de forma que a água não vá de forma natural até o açude. O circuito que irá controlar a bomba d´água terá que ligar a bomba, aguardar algum tempo e depois desliga-lo por certo tempo e essa atividade será cíclica.

### Materiais usados
  1. Arduino pro mini
      * O uso de um arduino pro mini em vez de um nano ou uno é justamente por causa do preço. O arduino pro mini custa em média R$13.

      * Esse aqui, eu mesmo que soldei mais no projeto eu usei outro que não tinha sido soldado.
      <img src="https://user-images.githubusercontent.com/32984446/52522518-88d18280-2c6d-11e9-897c-c180881201a2.jpeg" alt="" width="400"/>

  2. Relé
      * No meu caso, eu usei um que é ativado com 5V. A maioria que se encontra no mercado são de 12V ativação.
      <img src="https://user-images.githubusercontent.com/32984446/52522587-6a1fbb80-2c6e-11e9-8320-eb51edb1d92c.jpeg" alt="" width="300"/>

  3. Fonte com saída 5V
      * Essa eu retirei de um carregador de celular

      <img src="https://user-images.githubusercontent.com/32984446/52522632-ffbb4b00-2c6e-11e9-910f-0f624500e4bb.jpeg" alt="" width="200"/>

  4. Led e resistor
      * Usei Led amarelo e um resistor de 320 ohms para indicar que o relé está ligado.


  | Produto          | Preço em R$ |
  | ---------------- | ----------- |
  | Arduino pro mini | 13          |
  | Relé             | 3           |
  | Fonte 5V         | 10          |
  | Led e resistor   | <0.20       |
  |total:            | R$26.2      |


## Começando o projeto ...

### Oque é arduino pro mini e como programa-lo?
  O arduino pro mini é "1/3" arduino nano. Ele só tem o micro controlador em si (o ATmega328P de 5V). Portanto não tem conversor serial e regulador de tensão.

  <img src="https://user-images.githubusercontent.com/32984446/52629840-c74f8300-2ea1-11e9-8d9d-32a5db7c9691.jpg" alt="" width="400"/>

  <img src="https://user-images.githubusercontent.com/32984446/52629959-0b428800-2ea2-11e9-9f53-394328100c5c.jpg" alt="" width="400"/>

  Onde:
  * 1 é conversor serial.
  * 2 é regulador de tensão.
  * 3 é micro controlador.

  Para programa-lo vamos usar essa pecinha (também chamada de conversor serial):
  <img src="https://user-images.githubusercontent.com/32984446/52522678-af90b880-2c6f-11e9-8b1f-172cfc2e9ce7.jpeg" alt="" width="400"/>

  Se você repara, verá que ela tem o mesmo chip serial do Arduino nano.

  Fazendo a ligação. Atenção pois o Tx do conversor é o Rx do Arduino e vice-versa :).

  <br>
  <br>

  | Conversor serial | Arduino |
  | ---------------- | --------|
  | Vcc 5V           | Vcc     |
  | GND              | GND     |
  | Tx               | Rx      |
  | Rx               | Tx      |

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

Obs: no caso desse conversor serial, tem que apertar o botão resete do arduino assim que o código terminar de copilar para poder carregar o código.

Se tudo deu certo. O led da placa ficará piscando e imprimindo no monitor serial "I'm alive hahahaha  cont: " mais a variavel cont que vai se somando.

<br><br><br><br><br><br>

## Como usar o relé?

<img src="https://user-images.githubusercontent.com/32984446/52630855-755c2c80-2ea4-11e9-8b6e-46574a0e5892.jpeg" alt="" width="400"/>

Onde:
  * A e B é os pontos onde vamos energizar.
  * COM é o ponto da carga em comum. Onde vamos ligar o fio fase 127VAC.
  * NA é normalmente aberto. Se os pontos A e B não tiver energia não terá continuidade entre pontos NA e COM.
  * NF é normalmente fechado. Se os pontos A e b não tiver energia terá continuidade entre os pontos NF e COM.

Olhando na foto. Energizando os pontos A e B, o ponto normalmente aberto (NA) vai ficar fechado.

Obs: Dependendo do relé, tem que montar um circuito para tirar ruído. Bom, eu ainda estou estudando sobre isso...

## Juntando tudo

Ok. O correto fazer uma placa (PCB) e juntar todos os componentes. Mas... eu não tenho acesso a CNC (ainda está no papel a construção de uma). Então, vou juntar em uma placa genérica e soldar alguns pontos.

Fazendo essa ligação:
* Usando Fritzing <3
<img src="https://user-images.githubusercontent.com/32984446/52631560-3d55e900-2ea6-11e9-9a2b-87b9fdadad0a.png" alt="" width="400"/>

Na prática ficou assim:
* Frente :)
<img src="https://user-images.githubusercontent.com/32984446/52630288-fa464680-2ea2-11e9-972c-14234e467fb1.jpeg" alt="" width="400"/>

* Costa :)
<img src="https://user-images.githubusercontent.com/32984446/52630289-fa464680-2ea2-11e9-8ea8-41685cd07c62.jpeg" alt="" width="400"/>

E colocando em uma caixinha tipo essa aqui:

![](cad/caixinha_gif.gif)

### Código
O código não tem segredo. É mandar:
```c++
  //1h * 60min/1h => 60min*60s/1min => 3600s * 1000ms/1s => 3 600 000ms

  digitalWrite(4, HIGH);
  delay(1800000) //30min
  digitalWrite(4, LOW);
  delay(3600000) //1h
```
Obs: o tempo de delay não foi testado :/

## Packages (itens adicionais)

Tendo o principal que é o hardware (arduino). Todo outro processo de otimização como:
  * Gerenciar da irrigação das plantas.
  * Monitoramento do nível do açude.
  * Uma mini estação meteorológica para monitorar temperatura, índice de chuva e vento.

Todos esses processos tornar-se possíveis.


### Todo projetos esta disponível no Github 
https://github.com/wesley-cantarino/Sensor_Nivel_Acude
