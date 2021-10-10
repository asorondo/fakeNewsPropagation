[top]
components : fakenewsgenerator@fakenewsgenerator mediaOfficial@media mediaOpposition@media populationscoupled
out : out_port
in : stop
link : stop stop@fakenewsgenerator
link : out@fakenewsgenerator in@mediaOfficial
link : out@fakenewsgenerator in@mediaOpposition
link : out@mediaOfficial news@populationscoupled
link : out@mediaOpposition news@populationscoupled
link : out_port@populationscoupled out_port

[fakenewsgenerator]
frequency : 00:15:00:00
dist: 0.4

[mediaOfficial]
party : 1

[mediaOpposition]
party : 0

[populationscoupled]
components : socialnetworks@socialnetworks population1@population population2@population population3@population population4@population population5@population population6@population population7@population population8@population

out : out_port
in : news
link : news in@population1
link : news in@population2
link : news in@population3
link : news in@population4
 link : news in@population5
 link : news in@population6
 link : news in@population7
 link : news in@population8
link : out@population1 in@socialnetworks
link : out@population2 in@socialnetworks
link : out@population3 in@socialnetworks
link : out@population4 in@socialnetworks
 link : out@population5 in@socialnetworks
 link : out@population6 in@socialnetworks
 link : out@population7 in@socialnetworks
 link : out@population8 in@socialnetworks
 link : out@socialnetworks in@population1
 link : out@socialnetworks in@population2
 link : out@socialnetworks in@population3
 link : out@socialnetworks in@population4
 link : out@socialnetworks in@population5
 link : out@socialnetworks in@population6
 link : out@socialnetworks in@population7
 link : out@socialnetworks in@population8

link : out@socialnetworks out_port

[population1]
population_id : 1
age : 20
university_studies : 1
political_involvement : 0.95
employment_status : 0.9
economic_status : 0.5
centrality : 0.2
political_affinity: 0.1

[population2]
population_id : 2
age : 35
university_studies : 1
political_involvement : 0.6
employment_status : 0.6
economic_status : 0.2
centrality : 0.6
political_affinity: 0.7


[population3]
population_id : 3
age : 50
university_studies : 0
political_involvement : 0.15
employment_status : 0.1
economic_status : 0.95
centrality : 0.3
political_affinity: 0.9

[population4]
population_id : 4
age : 75
university_studies : 0
political_involvement : 0.05
employment_status : 0.1
economic_status : 0.1
centrality : 0.1
political_affinity: 0.1

[population5]
population_id : 5
age : 20
university_studies : 1
political_involvement : 0.7
employment_status : 0.3
economic_status : 0.4
centrality : 0.8
political_affinity: 0


[population6]
population_id : 6
age : 40
university_studies : 0
political_involvement : 0.3
employment_status : 0.4
economic_status : 0.78
centrality : 0.3
political_affinity:0.3

[population7]
population_id : 7
age : 55
university_studies : 1
political_involvement : 0.85
employment_status : 0.9
economic_status : 0.5
centrality : 0.2
political_affinity: 0.9

[population8]
population_id : 8
age : 65
university_studies : 0
political_involvement : 0.2
employment_status : 0.55
economic_status : 0.6
centrality : 0.4
political_affinity: 0.55