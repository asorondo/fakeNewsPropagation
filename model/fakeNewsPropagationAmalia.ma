[top]
components : fakenewsgenerator@fakenewsgenerator mediaOfficial@media mediaOpposition@media populationscoupled
out : out_port
in : stop
link : stop stop@fakenewsgenerator
link : out@fakenewsgenerator in@mediaOfficial
link : out@fakenewsgenerator in@mediaOpposition
link : out@mediaOfficial in@populationscoupled
link : out@mediaOpposition in@populationscoupled

[fakenewsgenerator]
frequency : 00:00:01:00

[mediaOfficial]
party : 1

[mediaOpposition]
party : 0

[populationscoupled]
components : socialnetwork@socialnetwork population1@population population2@population population3@population population4@population 
out : out_port
in : news
link : news in@population1
link : news in@population2
link : news in@population3
link : news in@population4
link : out@population1 in@socialnetwork
link : out@population2 in@socialnetwork
link : out@population3 in@socialnetwork
link : out@population4 in@socialnetwork
link : out@socialnetwork in@population1
link : out@socialnetwork in@population2
link : out@socialnetwork in@population3
link : out@socialnetwork in@population4

[population1]
population_id : 1
age : 20
university_studies : 0
political_involvement : 0.9
employment_status : 0.1
economic_status : 0.4
centrality : 0.8

[population2]
population_id : 2
age : 35
university_studies : 1
political_involvement : 0.6
employment_status : 0.6
economic_status : 0.5
centrality : 0.6

[population3]
population_id : 3
age : 50
university_studies : 1
political_involvement : 0.5
employment_status : 0.8
economic_status : 0.7
centrality : 0.3

[population4]
population_id : 4
age : 75
university_studies : 0
political_involvement : 0.2
employment_status : 0.2
economic_status : 0.4
centrality : 0.1