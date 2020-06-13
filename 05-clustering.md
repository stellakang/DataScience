# Cluster Analysis  

## What is Cluster Analysis   

### 1. Cluster  
: data objects의 모임  


- 같은 클러스터 안에 있으면 서로 비슷하다.  
- 다른 클래스에 있으면 서로 다르다.  

### 2. Cluster Analysis  
: 데이터의 특성을 바탕으로 데이터 간의 유사도를 구하는 것!  

- Unsupervied learning  
  : cluster analysis란 unsupervised learning으로, 학습시키는 동안 클래스 라벨이 주어지지 않는다.  
  
- Typical applications  
  - 데이터를 분석할 수 있는 독립적인 툴   
  - 다른 알고리즘을 위한 전처리 과정(클러스터링 분석->데이터마이닝 알고리즘 사용)   
  
- Applications  
  - Spatial Data Analysis  
    - 공간적으로 클러스터를 분석한다.  
    
  - Economic Science  
    - 손님의 행동을 기준으로 클러스터 분석이 가능하다.  
    
  - WWW  
    - 웹 방문기록 등을 통해 비슷한 접근 패턴을 그룹화 한다.  
    
  - Image Processing & Pattern Recognition  
  
  - Examples  
    - Marketing: 손님들을 비슷한 사람들끼리 그룹화하고 그 그룹을 타겟으로 마케팅한다.  
    - Land use: 토지 이용이 비슷한 지역끼리 그룹화한다.  
    - Insurance: 높은 클레임 코스트의 자동차 보험을 가진 그룹을 찾는다.  
    - City-planning: 집의 종류나 지역적인 위치 등으로 그룹화한다.  
    


## Quality and Requirements of Clustering  

- Quality: What is good clustering  
  - high intra-class similarity  
  - low inter-class similarity  
  
  
  - 클러스터링의 quality는 **그 클러스터링 방식의 similarity measure**과 **구현**과 **숨겨지 패턴을 파악하는 능력**으로 결정된다!  

- Measure the Quality of Clustering  
  - Dissimilarity/Similarity metric: d(i,j)  
    -> distance function으로 유사도를 표현하며 변수 타입마다 다르다!  
  - 매우 주관적이고 가중치는 attribute 마다 다른 가중치를 가져야 한다.  
  

- Requirements of Clustering in Data Mining  
  - 서로 다른 애트리뷰트들을 다룰 수 있어야 한다.  
  - 새로운 데이터가 추가될 때 잘 다룰 수 있어야 한다.  
  - 임의의 모양의 클러스터를 탐색한다.  
  - 파라미터를 정하는 것은 힘들기 때문에 최소의 파라미터 갯수를 필요로 해야 한다.  
  - 노이즈와 아웃라이어를 다룰 수 있어야 한다.  
  - 인풋 순서와 상관없이 동일한 결과를 가져올 수 있어야 한다.  
  - 높은 차원의 애트리뷰트를 대처할 수 있는 알고리즘이어야 한다.  
  - 아주 정확한 결과를 가져오더라도 너무 오랜 시간이 걸리면 그 알고리즘을 받아들일 수 없다.  
  - 유저의 특정한 조건을 포함할 수 있어야 한다.  


## A Categorization of Major Clustering Methods  

### 1. Major Clustering Approaches  

- Paritioning approach  
  - 다양한 파티션을 구성하고 어떤 기준에 따라 평가한다.   
  - Typical methods: k-means, k-medoids, CLARANS  
  
- Hierarchical approach  
  - 어떤 기준으로 계층적으로 데이터를 분리한다.   
  - Typical methods: Diana, Agnes, BIRCH, ROCK, CHAMELEON    
- Density-based approach  
  - 밀도함수를 기반으로 클러스터를 형성한다.   
  - Typical methods: DBSCAN, OPTICS    


### 2. Centroid, Radius, and Diameter of a cluster  
: 클러스터 내에서 centroid, radius, diameter의 정의!! 

- Centroid 
  : 클러스터의 중간!  
  - 각 애트리뷰트 값 끼리 더해서 평균을 구한다.  
  - Cm = sum(tip)/N (i: i th object, p: p th attribute)  
  
- Radius  
  : cluster의 모든 object에서 centroid까지 거리 제곱의 평균의 루트값    
  - Rm = root(sum((tip-cm)^2)/N)  
  
- Diameter  
  : 모든 오브젝트 페어들의 거리 제곱의 평균의 루트값  
  - Dm = root(sum((tip-tiq)^2)/N(N-1))  


- Typical Alternatives to Calculate the Distance between Clusters  
  : 두 클러스터 사이의 single link, complete link, average, centroid, medoid 정의!!  
  
  - Single link   
    : 한 클러스터의 원소와 다른 클러스터의 원소 사이의 최소 거리  
    - dis(Ki, Kj) = min(tip, tjq)  
    
  - Complete link  
    : 한 클러스터의 원소와 다른 클러스터의 원소 사이의 최대 거리  
    
  - Average  
    : 한 클러스터와 다른 클러스터 각각에서 원소를 하나씩 뽑은 모든 페어에 대해서 거리를 구한 후 평균을 구한 것  
    
  - Centroid  
    : 두 클러스터의 centroid사이의 거리!  
    - centroid는 실제 objec가 아니라 위치를 나타낸다!  
    
  - Medoid  
    : 두 클러스터의 medoid 사이의 거리!  
    - dist(Ki, Kj)=dis(Mi, Mj)  
    - Medoid: 클러스터에서 가장 가운데에 위치한 실제 object   
  

## Partitioning Methods  

### 1. Basic Concept  

- n개의 objects를 k개의 클러스터로 나누는 것으로 클러스터를 대표하는 값과 그 클러스터의 모든 objects 까지 거리의 제곱의 합이 최소가 되도록 한다.   
- 모든 파티션을 다 전개해보면 global optimal을 찾을 수 있겠지만 heuristic methods를 사용한다.   
- k값이 주어져야 한다!!   


### 2. The K-Means Clustering Method  

- Algorithm  
  - objects를 임의로 k 부분으로 나눈다.  
  - k 부분으로 나눠진 각 클러스터에 대해서 centroid 값을 계산한다.                                                   
  - 각 objects를 가장 가까운 seed point(centroid)의 클러스터로 다시 포함시킨다.  
  - 다시 centroid값을 계산으로 돌아가는 과정을 반복하여 클러스터가 바뀌지 않을 때까지 진행한다.  

- Characteristics  
  - Strength  
    - 상대적으로 효율적이다. 시간복잡도: O(nkt) (n=the number of objects, k is the number of clusters, t is the number of iterations)   
      **비교** PAM: O(k(n-k)^2), CLARA: O(ks^2+k(n-k))   

  - Comment  
    : 가끔 local optimum으로 빠진다.  
    (이니셜 시드에 따라서 달라진다.)  

  - Weakness  
    - categorical data인 경우는 불가, numerical attribute만 가능  
    - k를 미리 정해주어야 한다.  
    - 노이즈와 아웃라이어를 잘 다루지 못한다.  
    - non convex shape일 때는 부적절하다.  

- Variations of the K-Means Method  

  *numerical로 값을 대입을 못하니까 centroid와 d(X,Y)를 다시 정의해야지!!*  
  
  - k-modes: Handling categorical data  
    - centroid 대신 modes(최빈값) 사용  
      -> numerical data가 아닌 categorical data를 다룰 때 사용!!  
      
    - Dissimilarity d(X,Y): the number of total mismatches  
    - mode는 해당 object들과의 mismatch 수의 합이 가장 작은 벡터이다.  
      -> 애트리뷰트마다 가장 많은 object가 차지하는 값을 갖는다.  
  - k-prototype: A mixture of categorical and numerical data   
  
  
- K-Means Method: Problem  
  
  - outliers에 민감하다.  
    너무 아웃라이어의 값이 다른 object의 값과 차이가 큰 경우, 클러스터가 잘못 분리될 가능성이 높다.  
    
  ==> K-medoids  
  


### 3. The K-Medoids Clustering Method  
: PAM, CLARA, CLARANS  

- PAM  
  - Algorithm  
    - k개의 대표적인 objects를 임시로 선택한다. = medoids *k는 사람이 정하는 것*  
    - 선택되지 않은 모든 오브젝트들은 선택된 medoids 중에 가까운 것으로 할당한다.  
    - 랜덤으로 non-medoid object h를 고른다.  
    - total swapping cost TCih 를 계산한다.  
    - 만약 TCih < 0 이면 i medoid는 h로 바뀌고 선택되지 않은 오브젝트들은 가장 가까운 오브젝트로 할당된다.  
    - 변화가 없을 때까지 위 과정을 반복한다.  
    
  - Calculate total swapping cost  
    - 각 non selected 오브젝트 j마다 i 대신 h를 medoid로 했을 때 j가 속하는 medoid 까지의 거리 d(j,h)와  
      기존에 할당되어있던 j의 medoid 까지의 거리 d(j,i)의 차를 구하고 그 합을 total swapping cost라고 한다.   
    - 만약 j 오브젝트의 medoid가 i가 h로 바뀌는 것과 상관없이 동일하면 해당 코스트는 0이 된다.  
  
  - Problem  
    - k-means 보다 노이즈나 아웃라이어에 robust하다는 장점이 있지만,  
      큰 데이터셋에 대해서 잘 작동하지 않는다.  
      O(ik(n-k)^2)  
      n: the number of data, k: the number of clusters, i: the number of iterations  
    
    ==> CLARA  
    이젠 또 스케일 문제로 clara 방식 사용  
  

- CLARA  
  - 데이터셋의 샘플들을 뽑아내고 각 샘플마다 PAM을 적용하여 클러스터 결과를 가져온다.    
  - Strength  
    : 샘플링한 데이터셋을 사용하기 때문에 더 큰 데이터를 다룰 수 있다.  
    
  - Weakness  
    - 샘플 사이즈에 따라 효율성이 달라진다.  
      : 너무 샘플 사이즈가 작으면 성능이 안좋을 수 있다.  
    - 샘플을 잘 선정하지 않으면 좋은 클러스터링을 할 수 없다.  
  

## Hierarchical Methods  

### 1. Hierarchical Clustering  
: distance matrix를 사용한다. k는 필요하지 않지만 termination condition이 필요하다.  


- agglomerative(AGNES)    
  - bottom-up  
  - single-link method를 사용한다!!  
    -> minimum distance가 가장 작은 (==가장 유사도가 높은) 클러스터끼리 머지한다.  
  - 나중에 모든 노드가 같은 클러스터에 속하게 된다.  
  - Complexity: n(n-1)/2  (n개의 클러스터 중에 머지할 두개를 고르기 nC2)  
  
  - *Dendrogram*  
    - 클러스터가 머지되는 순서를 보여준다.  
    - 특정 레벨에서 자르면 각각 덩어리가 클러스터가 된다.  

- divisive(DIANA)  
  - top-down  
  - 모든 n개의 objects가 하나의 클러스터를 이룬다.   
  - 나중에 모든 노드가 하나의 클러스터가 된다.  
  - Complexity: 2^(n-1) - 1  
    (n개의 오브젝트가 2개로 나뉠때 0이나 1선택할 수 있다고 보고 한쪽으로 몰리지 않도록 -2하면 2^n-2 이다.  
     그리고 0,1 서로 바뀌어도 되니까 2로 나누면 2^n-1 -1이 된다. 너무 많다!!)  
     
  - Algorithm in detail  
    - 가장 다른 모든 오브젝트와의 average dissimilarity가 큰 오브젝트를 골라서 splinter group에 넣는다.  
    - splinter group이 아닌 모든 오브젝트 i에 대해서  
      Di = [average d(i,j), j not in splinter group] - [average d(i,j), j in splinter group]  
      를 계산한다.  
    - Di가 가장 큰 오브젝트 h를 찾고, 만약 Dh>0 이면, h는 splinter group에 가까우므로 splinter group에 포함시킨다.  
    - Dh<0 이 나올때까지 step 2,3을 계속 반복하고 음수가 나오면 그 전까지 분리된 그룹을 바탕으로 두개로 나눈다.  
    - diameter가 가장 큰 클러스터를 선택하고 이전 단계를 다시 반복한다.  
    - 모든 클러스터들이 한 개의 오브젝트만 남을 때까지 반복한다.  

### 2. Advanced Hierarchical Clustering Method  
: agglomerative clustering method의 문제는 많은 오브젝트들을 다루기 어렵다. (time complexity가 크다.)   

- BIRCH  
  keyword: CF-tree, numeric data    
  
  - Clustering Feature: (N, LS, SS)  
    - 클러스터의 특성을 저장.  
    - N: The number of data points  
    - LS: dataset의 모든 합(x좌표는 x좌표끼리) -> **N으로 나눠서 centroid 구할 수 있음**   
    - SS: dataset의 제곱의 합(x좌표는 x좌표끼리) -> **N(N-1)로 나누고 루트씌우면 diameter 구할 수 있음**     
  
  - CF-tree  
    - height-balanced tree  
    - non-leaf node는 자식의 CF의 합을 저장한다.  
    - 파라미터  
      Branching factor: 최대 자식 수를 명시한다.    
      threshold: leaf node에 저장되는 최대 diameter를 명시한다.  
  
  - Algorithm  
    - scan DB하여 CF tree를 빌드한다.  
      처음엔 아무것도 없고 첫번째 object를 추가하면 1개의 cf가 생긴다. (이때 n=1, linear=값 자신, square=자신의 제곱)  
      여기서 하나 더 추가하면 n=2된다. 계속 반복하여 diameter가 threshold를 넘으면 split하여 또다른 cf를 만든다.  
      leaf node=1, 2 cf 상태에서 이렇게 cf를 계속 만들어가다가 branching factor를 넘으면 2 leaf node로 균형되게 분리한다.  
      리프노드 만들고 또 넘치면 나누는 식으로 반복한다.  
    - 임의의 클러스터링 알고리즘을 사용하여 리프노드를 클러스터링한다.  
    
  - Scales linearly  
    - 한 번의 스캔으로 좋은 클러스터링을 찾을 수 있다.  
  
  - Weakness  
    - numeric data를 다루고 data의 순서에 따라 결과가 달라진다.  
    
    

- ROCK  
  keyword: categorical data, link analysis(not distance-based)     
  
  - Similarity measure: "link measure"    
    - jaccard coefficient  
      Sim(T1,T2)=|intersection(T1,T2)|/|T1 U T2|  
      -> jaccard coefficient의 문제점: 같은 클러스터 안의 object끼리 similarity보다 다른 클러스터의 object끼리 similarity가 더 높은 경우가 발생  
  
    - links  
      The number of common neighbors  
      두 페어의 jc가 threshold를 넘으면 neighbors이다.  

- CHAMELEON  
  keyword: dynamic modeling  
  
    
  - Algorithm  
    - k-nearest neighbor 그래프를 그린다.  
      - Node: object, edge: k-nearest neighbor's link, weight: similarity  
    
    - graph partitioning algorithm: metis  
      작은 클러스터들로 클러스터링한다.  
      -> 그래프를 거의 같은 사이즈의 서브그래프로 나눈다.  
    - agglomerative hierarchical clustering algorithm  
      내부 interconnectivity, closeness보다 interconnectivity, closeness가 큰 클러스터 끼리 합친다.  
      -> relative interconnectivity  
      RI(Ci,Cj) = |EC{ci,cj}|/1/2(|ECci|+|ECcj|)  
      EC는 weight sum of cut edges이다.  
      -> relative closeness  
      RC(Ci,Cj) 식은 자료 참고    

## Density-Based Methods   
: distance만으로 클러스터링하는 것이 아닌, density를 기반으로 클러스터링한다.   

### 1. Basic Concepts  

  - Major features  
    - 임의의 모양의 클러스터를 찾을 수 있다.  
    - 노이즈를 다룰 수 있다.  
    - 한 번의 스캔으로 효율적이다.  
    - 종료 조건으로 density parameter가 필요하다.  
    
  - Several interesting studies  
    - DBSCAN  
    - OPTICS  
    - CLIQUE  
    
  - Two parameters  
    - Eps  
    주변을 포함하는 최대 radius(반지름)    
    eps를 반지름으로 하는 원을 이룬다.   
    
    - MinPts  
    eps가 포함하는 범위의 최소 points 갯수  
    
    - Neps(p): {q belongs to D | dist(p,q)<=Eps}  
    
  - Directly density-reachable   
    a point p is directly density-reachable from a point q if      
    - p belongs to Neps(q)  
    - |Neps(q)|>=Minpts (이런 경우 q를 core point라고 한다!! core point condition)   
    > p가 q의 neighborhood에 속하고 q의 neighborhood의 수가 minpts 이상인 경우    
      그 반대는 성립하지 않는다!!  
  
  - Density-reachable  
    a point p is density-reachable from a point q if    
    - there is a chain of points p1, ..., pn, p1=q, pn=p such that pi+1 is directly density-reachable from pi    
    > p1에서 q까지 directly density-reachable한 objects들이 연쇄적으로 있는 경우  
    
  - Density-connected  
    a point p is density-connected to a point q if  
    - there is a point o such that both p and q are density-reachable from o w.r.t eps and minpts  
    > q가 o로부터 density-reachable하고 p가 o로부터 density-reachable하면 p와 q는 density connected하다.  
    
### 2. DBSCAN  

- keyword: density-based, arbitrary shape   
- maximal set of density-connected points   

- Algorithm  
  - 임의로 p를 고른다.   
  - p에서 density-reachable한 모든 point들을 찾는다.   
  - p가 core point이면 클러스터가 형성되고 아니면 border point 이므로 다른 point를 방문한다.  
  - 모든 points들을 방문할 때까지 진행한다.  

-> 파라미터에 따라 클러스터가 다르게 형성됨!!  

### 3. OPTICS  

- Concepts  
  - point를 ordering하는 것!!  
  - idea  
    - core distance(of o)    
      object가 core point가 되도록 하는 거리  
    - rechability distance(of p from o)    
      r(p,o) = max(core-distance(o), d(o,p))   

- Process  
  - 시작점 하나를 정하여 그래프에 표기, reachablity distance가 아직 정의되지 않은 상태이니까 undefined로 둔다.  
  - core distance를 기반으로 다른 모든 점의 reachable distance를 갱신한다.  
  - 가장 가까운 점을 두번째 점으로 하여 그래프 두번째에 표기  
  - 두번째를 중심으로 reachable distance를 갱신하고 가장 가까운 점을 세번째 점으로 고른다.  
  - 계속 반복하면 eps를 정하여 그것을 기준으로 잘라내면 클러스터가 각각 생성된다.  


## Outlier Analysis  

### 1. What is Outlier Discovery  

- 다른 데이터와 매우 다른 objects  

- Problem  
  : 아웃라이어를 정의, 찾는 것  
  
- Applications  
  - 신용카드 사기 
  - 텔레콤 사기   
  - 사용자 분석   
  - 의료 분석   
  

### 2. Outlier Discovery: Statistical Approaches  

- Use discordancy tests depending on  
  - data distribution: 예를 들어, normal distribution    
  - distribution parameter: mean, variance  
  - number of expected outliers: 예를들어, 위, 아래 2.5퍼센트    
  
- Drawbacks  
  - single attribute를 위한 테스트가 많다. -> 실제로 데이터가 많은 애트리뷰트를 가지고 있으니    
  - 많은 경우, data distribution이 잘 알려져있지 않다.    

### 3. Outlier Discovery: Distance-Based Approach  

- 위의 문제를 해결하기 위한 방법!!  
  multi-dimensional & without knowing data distribution  
- Distance-based outlier(DB(p,D)-outlier): 모든 페어에 대해서 distance 계산하고 p비율 이상 점o에서 D거리 이상 떨어져있으면 o는 outlier이다.    
- Algorithms for mining distance-based outliers  
  - index-based algorithm  
  - nested-loop algorithm  
  - cell-based algorithm   

- Density-based local outlier detection  
  - distance-based는 global distance distribution을 기반으로 하므로 uniform하게 분포되어있지 않으면 힘들다.  
    -> 그래서 이를 개선하기 위해 여기선 local로!!    
  - DB(p,D)-outlier 방법을 사용하면 D값을 설정해야 하는데 각 클러스터마다 떨어진 거리가 다르면 힘들어지므로 제안된 방식!  


