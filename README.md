# WorkinC Projeto Integrado Multidisciplinar, desenvolvido em C.

Projeto consiste em uma Startup de infraestrutura de T.I., utilizando um programa de chamados desenvolvido em C, para cadastrar seus usuários e clientes, possibilitando trabalho mútuo de usuários.

Acesso Inicial, login com senha mascarada, fazendo distinção de tipo de usuário, definindo assim os privilégios que o usuário possuirá.
Criados telas individuais com extensão .h e adicionados todas as telas em uma main.h, que é referenciada pela main principal (main.c), trazendo ao usuário a possibilidade de utilizar todas as telas, conforme o privilégio dos usuários.
Utilizando banco de dados básico, salvando os dados em txt, dados sensíveis salvados em binário.

Funcionalidade das Telas:
- Login Inicial ( Caso não haja usuário cadastrado criado uma void que cria um usuário padrão )
- Cadastro de usuários (Atribuído ao usuário 'ADMIN', podendo assim cadastrar novos usuários do tipo 'USER' ou 'ADMIN', salvando os dados em txt [dados sensíveis salvos em binário.])
- Listagem de usuários cadastrados (Atríbuído ao usuário 'ADMIN', faz a leitura dos dados em binário e apresenta no propraga os usuários cadastrados.)
- Cadastro de Clientes (Atribuído ao usuário 'ADMIN', cadastrando os dados dos clientes em txt)
- Listagem de clientes cadastrados (Atribuído aos usuários 'ADMIN' e 'USER', consultando os usuários cadastrados em txt e apresentando no programa)
- Abertura de chamado (Atribuído aos usuários 'ADMIN' e 'USER', possibilitando abertura de chamados, adicionando título ao chamado, descrição e atribuição de clientes ao chamado, informado o custo do chamado e calculado desconto para caso de pagamentos à vista, salvando os dados do chamado em txt)
- Listagem de chamados (Atribuído aos usuários 'ADMIN' e 'USER', consutultado em txt todos os chamados que foram abertos)
- Finalização de chamados (Atribuído aos usuários 'ADMIN' e 'USER', possibilitando pesquisa de chamados pelo nome do cliente e possibilitando finalização dos chamados abertos)
- Gerar Relatório (Atribuído ao usuário 'ADMIN', possibilitando geração de um relatório filtrando por nome do cliente, mês e ano em que o relatório foi gerado, faz a leitura dos dados dos chamados cadastrados em binário e salva em um novo txt possibilitando consulta)
