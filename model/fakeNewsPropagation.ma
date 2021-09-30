[Top]
components : FakeNewsGenerator@Generator  
out : out generator_out 
in : setNetworkDelay 
Link : setNetworkDelay setDelay@network
Link : out@TrafficGenerator in@network
Link : out@TrafficGenerator generator_out
Link : out@network out

[FakeNewsGenerator]
distribution : Constant
value : 10
initial : 0
increment : 1

[OfficialMedia]
components : networkDelay@networkDelayType 
out : out 
in : in setDelay 
Link : in in@networkDelay
Link : setDelay setDelay@networkDelay
Link : out@networkDelay out

[OppositionMedia]
components : networkDelay@networkDelayType 
out : out 
in : in setDelay 
Link : in in@networkDelay
Link : setDelay setDelay@networkDelay
Link : out@networkDelay out

[socialNetworks]
components : networkDelay@networkDelayType 
out : out 
in : in setDelay 
Link : in in@networkDelay
Link : setDelay setDelay@networkDelay
Link : out@networkDelay out

[population1]
components : networkDelay@networkDelayType 
out : out 
in : in setDelay 
Link : in in@networkDelay
Link : setDelay setDelay@networkDelay
Link : out@networkDelay out

[population2]
components : networkDelay@networkDelayType 
out : out 
in : in setDelay 
Link : in in@networkDelay
Link : setDelay setDelay@networkDelay
Link : out@networkDelay out

[population3]
components : networkDelay@networkDelayType 
out : out 
in : in setDelay 
Link : in in@networkDelay
Link : setDelay setDelay@networkDelay
Link : out@networkDelay out

[population4]
components : networkDelay@networkDelayType 
out : out 
in : in setDelay 
Link : in in@networkDelay
Link : setDelay setDelay@networkDelay
Link : out@networkDelay out


