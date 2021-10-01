[top]
components : fakenewsgenerator@fakenewsgenerator
out : out_port
in : stop
link : stop stop@fakenewsgenerator
link : out@fakenewsgenerator out_port

[fakenewsgenerator]
frequency : 00:00:01:00