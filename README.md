# Introdução ao RTOS
O uso de um RTOS (Real-Time Operating System) é essencial em projetos que exigem a execução de tarefas em tempo real com prazos determinísticos. Um RTOS fornece uma estrutura de software que permite o agendamento de tarefas, gerenciamento de prioridades, sincronização e comunicação entre tarefas, além de garantir uma resposta rápida a eventos críticos. Com sua eficiência e recursos de temporização precisa, um RTOS pode oferecer um ambiente confiável e escalável para o desenvolvimento de sistemas embarcados, permitindo modularidade, facilidade de manutenção e o cumprimento de requisitos de tempo real.


# Multitarefas com FreeRTOS
O FreeRTOS é um sistema operacional de tempo real que suporta a execução de multitarefas em sistemas embarcados. Com o FreeRTOS, é possível criar várias tarefas independentes que são agendadas e executadas de acordo com suas prioridades. O kernel do FreeRTOS permite a comutação rápida e eficiente entre as tarefas, garantindo que cada tarefa tenha sua fatia de tempo para executar. Além disso, o FreeRTOS fornece mecanismos de sincronização e comunicação entre as tarefas, permitindo a troca de dados e a coordenação de atividades. Com o suporte à multitarefa do FreeRTOS, é possível desenvolver sistemas complexos com tarefas concorrentes, oferecendo modularidade, escalabilidade e tempo de resposta determinístico.

# Sincronização de tarefas
Em um ambiente de produção mais complexo, onde as tarefas compartilham recursos críticos, é necessário utilizar mecanismos de sincronização, como semáforos e mutexes. Esses recursos garantem a coordenação adequada entre as tarefas, evitando conflitos de acesso e garantindo a integridade dos dados compartilhados. Esses mecanismos permitem que as tarefas aguardem a disponibilidade de recursos antes de acessá-los e garantem acesso exclusivo a recursos compartilhados. Ao utilizar semáforos e mutexes, é possível evitar problemas como condições de corrida e inconsistências nos dados, assegurando um comportamento correto e previsível do sistema.


# Reações baseadas em condições de tempo real
No código fornecido, a tarefa "TaskReadTemperature" lê a temperatura de um sensor simulado e atualiza a variável volátil "temperature". Dependendo do valor da temperatura, as tarefas "TaskBlink2" e "TaskBlink3" acendem ou apagam LEDs conectados a pinos específicos. Se a temperatura for maior ou igual a 26.00 graus, o LED ligado ao "led_pin_2" é acionado, indicando a necessidade de ligar um ar-condicionado. Se a temperatura for menor ou igual a 10.00 graus, o LED ligado ao "led_pin_3" é acionado, indicando a necessidade de ligar um aquecedor. Essas reações em tempo real permitem um feedback visual com base na temperatura medida pelo sensor.


# Vantagens
O uso de um RTOS (sistema operacional em tempo real) em aplicações IoT traz diversas vantagens. Ele permite a execução simultânea de várias tarefas, garantindo a eficiência e independência de funcionalidades. Além disso, oferece agendamento e priorização de tarefas, gerenciamento de recursos eficiente, facilita o desenvolvimento e proporciona escalabilidade para expansões futuras. Em resumo, um RTOS torna as aplicações IoT mais robustas, responsivas e capazes de lidar com os desafios do ambiente interconectado.

# Esquemático montado no Proteus
<div align=center>
<img height="500em" src="./assets/img/esquematico.png">
</div>