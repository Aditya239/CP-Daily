n, w, u, v, begin, end = [int(x) for x in raw_input().split()]
cross = float(w)/float(v)
u = float(u)
ships = []
K = 0.0
for i in range(n):
    laneinfo = raw_input().split()
    eastbound = 1 if laneinfo[0]=='E' else -1
    m = int(laneinfo[1])
    laneinfo = [float(k) for k in laneinfo[2:]]
    shipslane = [[-eastbound*laneinfo[2*j+1]/u - (i+1)*cross, (laneinfo[2*j] - eastbound*laneinfo[2*j+1])/u - i*cross] for j in range(m)]
    shipslane = [ship_ for ship_ in shipslane if ship_[0] < float(end)]
    ships += shipslane
ships=sorted(ships, key=lambda x: x[0])
free_since = float(begin)
for j in range(len(ships)):
    K = max(ships[j][0] - free_since, K)
    free_since = max(free_since, ships[j][1])
K = max(K, float(end) - free_since);
print(K)
