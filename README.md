# Oficina-de-Integracao-I
Projeto Autonomia Para Deficientes Visuais

Este é um projeto que será desenvolvido para a disciplina de Oficina de Integração I da Universidade Tecnológica Federal do Paraná Campus Cornélio Procópio.

PROBLEMAS E PREMISSAS 

  Deficientes visuais possuem dificuldades em se locomoverem em ambientes desconhecidos sem o auxílio de terceiros (ajudante, cão-guia etc) ou equipamentos (bengala). A dependência, na maior parte das vezes, leva a pessoa a apresentar insegurança se houver a necessidade, por exemplo, de sair de sua casa e ir ao mercado se ela não possuir, naquele momento, alguém ou algum objeto (bengala) para guiá-lo ou ajudá-lo a chegar até o local.

  O principal problema em depender de uma pessoa para auxiliar o deficiente visual em suas saídas é que nem sempre tal pessoa estará disponível. Ou, no caso de uma contratada, o custo é elevado. Tal custo elevado também é válido para treinar ou adquirir um cão-guia.
  
  No caso da bengala, que é o objeto mais utilizado no auxílio dos deficientes visuais e que não possui um custo elevado, existem certas limitações quanto ao seu uso. Por exemplo, a detecção de obstáculos em regiões acima da cintura e, utilizando a bengala, uma das mãos do usuário precisa se dedicar apenas à essa atividade. Por tais motivos, a ideia principal deste projeto é desenvolver um dispositivo corporal que dê uma maior indepêndencia ao deficiente visual.


OBJETIVOS 

  O projeto tem como objetivo minimizar a dependência e dificuldade de locomoção dos deficientes visuais por meio da utilização de um dispositivo corporal que seja capaz de alertar o usuário de possíveis obstáculos que estejam em seu caminho através de sistemas de alertas sensorais.

REFERENCIAL TEÓRICO

  Arduíno: Plataforma de prototipagem eletrônica de baixo custo e de fácil utilização.
  
  Sensor Ultrassônico: Dispositivo capaz de enviar e receber ondas sonoras que permitirão o cálculo da distância do usuário do o possível obstáculo.

FUNCIONALIDADES

  O sensor ultrassônico enviará ondas sonoras ao ambiente e as receberá de volta. O Arduíno, com esta informação, é capaz de calcular a distância entre o obstáculo e o sensor. Com isso, o dispositivo vibrará de maneira inversamente proporcional à distância que o usuário se encontra do obstáculo (quanto menor a distância, mais intensa a vibração), e também emitirá alertas sonoros, cuja intensidade e volume também serão inversamente proporcionais à distância do usuário ao obstáculo.


