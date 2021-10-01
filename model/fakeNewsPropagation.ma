[top]
components : fakenewsgenerator@fakenewsgenerator media@media
out : out_port
in : stop
link : stop stop@fakenewsgenerator
link : out@fakenewsgenerator in@media
link : out@media out_port

[fakenewsgenerator]
frequency : 00:00:01:00

[media]
party : 1
