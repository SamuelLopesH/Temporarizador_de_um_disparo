# Temporizador de Um Disparo com Raspberry Pi Pico

Este projeto implementa um temporizador de um disparo utilizando um Raspberry Pi Pico. O código controla três LEDs (Vermelho, Azul e Verde) que são ligados simultaneamente ao pressionar um botão. Após 3 segundos, os LEDs são desligados em sequência, com intervalos de 3 segundos entre cada desligamento.

## Componentes Necessários

- Raspberry Pi Pico
- 1 LED Vermelho
- 1 LED Azul
- 1 LED Verde
- 1 Botão
- Resistores (220Ω recomendado para cada LED e 10kΩ para o botão)
- Protoboard e jumpers

## Esquema de Conexão

- **LED Vermelho**: Conectado ao pino GP13
- **LED Azul**: Conectado ao pino GP12
- **LED Verde**: Conectado ao pino GP11
- **Botão**: Conectado ao pino GP5 e GND (com resistor pull-up interno ativado)
- **GND**: Todos os LEDs devem ser conectados ao GND através de resistores.

## Funcionamento

1. Ao pressionar o botão, os três LEDs são ligados simultaneamente.
2. Após 3 segundos, o LED Vermelho é desligado.
3. Após mais 3 segundos, o LED Azul é desligado.
4. Após mais 3 segundos, o LED Verde é desligado.
5. O sistema aguarda o próximo pressionamento do botão para reiniciar o ciclo.

## Como Executar

1. Conecte os componentes conforme o esquema de conexão.
2. Compile e carregue o código no Raspberry Pi Pico.
3. Pressione o botão para iniciar a sequência de desligamento dos LEDs.

## Links Úteis

- **Simulação no Wokwi**: [Clique aqui para acessar a simulação](https://wokwi.com/projects/422015197095132161)
- **Repositório no GitHub**: [Clique aqui para acessar o repositório](https://github.com/SamuelLopesH/Temporarizador_de_um_disparo)

