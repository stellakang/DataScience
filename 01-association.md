# Mining Frequent Patterns, Association and Correlations  

## Basic Concepts and a road map  
>"상점에서 어떤 물건들이 주로 함께 구입되는지, 또는 물건이 구입되는 순서는?"  
>"이 약에 예민한 dna는 어떤 것인지?"  
<br>  

### "데이터 안에 내재된 규칙을 찾기 위해 **Frequent Pattern Analysis** 를 한다!!"  
<br>  

### 1. Frequent pattern  
= 데이터셋에서 자주 등장하는 패턴!     
a pattern(a set of items, subsequences, substructures ...) that occurs frequently in a data set  
<br>  

### 2. Frequent Pattern Analysis 응용 분야      
Basket data analysis | cross-marketing | catalog design | sale campaign analysis | Web log analysis | DNA sequence analysis  
> 구매자 물품 목록을 가지고 분석하거나, 크로스 마케팅을 위해 소비자의 구매 형태를 고려하여 특정 물품을 추가로 판매하거나,   
선전을 목적으로 카탈로그를 디자인하거나 클릭 스트림을 가지고 분석하거나 DNA 분석하는 등등  
<br>  

### 3. Frequent Pattern Analysis 가 중요한 이유  
 많은 data mining task의 토대가 된다. -> 아래의 다양한 data mining task가 용이해진다.  
> Association, correlation, causality analysis  
Sequential, structural patterns  
Pattern analysis in spatiotemporal, multimedia, time-series and stream data  
Classification : associative classification  
Cluster analysis : frequent pattern-based clustering  
Semantic data compression  
<br>  

### 4. Concepts  
#### 1) Association rule X -> Y   
- **support** : probability that a transaction contains X U Y  
  > (아이템셋 X와 Y를 모두 포함하는 트랜잭션의 수)/(전체 트랜잭션의 수)  

- **confidence** : conditional probability that a transaction having X also contains Y  
  > (아이템셋 Y를 포함하는 트랜잭션의 수)/(X를 포함하는 트랜잭션의 수)  
<br>  

**문제)**    
min sup = 50%, min conf = 50% 일때, 모든 association rules X -> Y를 찾아라.  
| Transaction-id | Items bought |
| -------- | :------: |
| 10 | A,B,D |
| 20 | A,C,D |
| 30 | A,D,E |
| 40 | B,E,F |
| 50 | B,C,D,E,F |   

**문제-1) Frequent pattern**   
= min support 이상인 아이템셋  
symmetric : AD가 frequent pattern <=> DA가 frequent pattern     
Downward closure property : Any subset of a frequent itemset must be frequent  
답 : { A:3, B:3, D:4, E:3, AD:3 }  
  
**문제-2) Association rules**  
답:   
A -> D (sup: 60%, conf: 100%)  
D -> A (sup: 60%, conf: 75%)  
<br>  

#### 2) Closed Patterns and Max Patterns  
FP 문제점 : sub pattern을 모두 고려해야 한다. -> **performance의 문제**  
solution : Mine closed patterns and max patterns instead   


- **Closed patterns**   
itemset X is closed if X is frequent and there exists no super-pattern Y with the same support as X    
  > frequent pattern 이고 같은 support값을 갖는 super pattern이 없음!!   

  CLOSET : Mining Closed Patterns   
  원래는 frequent itmes를 다 구하고, superset의 support가 같은 frequent itemset은 지우는 방식이지만 너무 오래걸림.  
  **FP-tree 이용** : FP-tree에서 d를 가진 transaction은 cfa를 가지므로 cfad는 frequent closed pattern이다.    
  
- **Max-patterns**   
itemset X is a max-pattern if X is frequent and there exists no frequent super-pattern Y    
  > 더 늘릴게 없어!! frequent pattern 이고 frequent super pattern이 없음!!     
  
  MaxMiner : Mining Max-patterns  
  **apriori를 기반**으로 하되, max pattern만 효과적으로 구하기 위한 방법  
  set-enumeration tree를 이용하여 pruning하면서 진행  
  1st scan -> frequent items찾고 증가하는 순으로 정렬    
  2nd scan -> 2-itemsets와 potential max-patterns의 support구하기  
  => BCDE가 max pattern이면 subsets 역시 frequent하니까 구할 필요 없음.  
  => AC가 infrequent하면 ABC는 볼 필요 없음.  
                
<br><br>       
       
## Efficient and scalable frequent itemset mining methods   
*Frequent pattern을 찾아내는 일반적인 방법 3가지!*  
<br>  

### 1. Apriori     
> 후보 생성하고 테스트하는 과정 반복하면서 Frequent pattern을 찾아낸다.  
단, 후보 생성시 subset이 frequent하지 않으면 생성 안함.  

**Apriori pruning principle** : If there is any itemset which is infrequent, its superset should not be generated/tested!  

<br>  

**Method**  
- Initially, scan DB once to get frequent 1-itemset  
- Generate candidate itemsets of length (k+1) from frequent itemsets of length k  
- Test the candidates against DB  
- Terminate when no frequent or candidate set can be generated  
> a. k-itemset의 후보들 DB를 스캔 : k-itemset with min support -> frequent k-itemset   
  b. (k+1)-itemset의 후보 정하기 : sub itemset이 모두 frequent한 itemset     
  c. 더 이상 frequent itemset이나 candidate이 생성되지 않을 때까지 a,b 과정 반복   

<br>  

**Issue**  
- generate candidates  
  self-joining : abc, abd 로부터 abcd 생성  
  pruning : acde는 L3에 ade가 없으니까 제거  
- count supports of candidates  

<br>  

**Challenges**  
= Apriori 알고리즘 개선할 때 고려해야 할 점  
- DB scan 많이 한다. == maximum frequent pattern length 만큼  
- candidates 수가 많다. -> 100개 item의 경우 2^100-1개의 candidates, 100번 scan     
- support counting 하는 데에 업무량 많다.  

<br>  

**Improving Apriori**   

**- Reduce the number of transaction database scans**   

  **a. Partition**    
     scan1 : DB를 k개로 나누면 각 local databases(=partition)에서 local minSup (=minSup/k)이 넘는 local frequent patterns 찾는다.  
     scan2 : local frequent patterns 이더라도 global frequent patterns는 아닐 수 있기 때문에 확인  
     이때, partition은 각각 메인메모리에 있음  

  **b. Sampling for Frequent Patterns**     
  
  
  **<기존 sampling>**  
  original database -- sample --> SDB -- apriori --> local frequent pattern(minSup은 더 작은 값 사용)  
  문제점 : local frequent는 실제로 frequent patterns가 아닐 수 있고 전체 DB에서 frequent patterns가 빠졌을 수 있다.   
  
  
  **<보완한 sampling>**   
  **scan1** -> S, NB에서 frequent itemsets 찾기  
  S : local frequent pattern  
  NB : S에는 없지만, S에 모든 subsets가 있는 itemsets를 포함시킨다.(빠진 frequent pattern을 찾기 위해)  
  **scan2** -> NB에서 frequent itemset으로 포함되면서 frequent patterns가 될 수 있는 것들을 위함  

  **c. DIC**  
     같은 스캔에서 길이가 다른 itemsets가 후보로 들어있다.  
     a,d가 frequent이면 2-itemsets 탐색하기 시작, bcd의 모든 subsets가 frequent이면 bcd 탐색 시작  
  
<br>  

**- Shrink the number of candidates**   
  
  **a. DHP**   
     DB 스캔 한 번 할 때, k-itemsets의 support를 계산하는 동시에 (k+1)-itemsets를 위한 해시테이블을 만든다.  
     -> hash table의 각 row는 hash bucket을 의미하며 hash값이 같은 itemset끼리 같은 hash bucket에 위치하도록 count
     -> hash bucket count가 minSup보다 작으면 frequent pattern에서 제외  
     -> candidate를 줄이는데 효과적   

<br>    

**- Facilitate support counting of candidates**     


<br>  

### 2. Frequent pattern growth (FPgrowth)      
: Mining Frequent Patterns Without Candidate Generation  
: FP-tree를 기반으로 한다.  
<br>  

   **순서**  
1) DB를 스캔하고, frequent 1-itemset 찾기  
2) f-list 만들기 : frequent item의 frequency가 감소하는 순서대로 정렬  
   F-list = f(4) - c(4) - a(3) - b(3) - m(3) - p(3)  
3) DB를 다시 스캔해서 FP-tree 만들기  
   root는 {}로 비워두고, 각 transaction 마다 frequent items를 정렬시켜 tree에 이어붙인다.    
   이때, 이미 동일한 브랜치가 있으면 count를 증가시키고 없으면 브랜치를 새로 만든다. f:3 이런식으로 노드 표기  
   frequent 1-item과 frequency가 적혀있는 header table에 시작점부터 존재하는 item까지 이어준다.  
4) Pattern을 나누어 생각해보자.    
   F-list = f-c-a-b-m-p 인 경우, 아래와 같이 나눌 수 있다.    
   Patterns containing p, Patterns having m but no p, Patterns having b but no m,p ..., Patterns having f  
5) 각 아이템마다 conditional pattern base를 구한다.     
   a. frequent item header table에서 p의 링크를 따라간다.  
   b. p의 prefix path를 모두 이어서 p's conditional pattern base 표를 만든다.  
   
**Header Table**  
| Item | frequency | head |
| ----- | :------: | -- |
| f | 4 ||
| c | 4 ||
| a | 3 ||
| b | 3 ||
| m | 3 ||   
| p | 3 ||  

**Conditional pattern bases**  
| item | cond. pattern base |
| ----- | ----------- |
| c | f:3 |
| a | fc:3 |
| b | fca:1, f:1, c:1 |
| m | fca:2, fcab:1 |   
| p | fcam:2, cb:1 |

6) Conditional pattern base에서 Conditional FP-tree 만들기   
   예를 들어, p의 모든 conditional pattern base를 합쳐서 minSup가 넘는 items에 대해 p-conditional FP-tree를 만든다.  
   
   
   Conditional FP-tree에서 모든 frequent itemsets 구하기     
   예를 들어, f(3)-c(3)-a(3)이 m-conditional FP-tree 이면     
   -> fm, cm, am, fam, cam, fcm, fcam  
   만약, conditional FP-tree에 single prefix path가 있으면 single 부분과 아닌 부분으로 나누어서 각각 구한 후, 붙인다.
   
   이 과정을 빈도수가 낮은 아이템부터 conditional FP-tree를 생성해나가다가  
   FP-tree가 비어있거나, single path만 포함할 때까지 진행한다.       
   
<br>  

**장점**  

1) completeness = loseless information  
   모든 frequent pattern 포함한다.  
   
2) compactness = remove irrelevant info  
   더 빈도가 높은 item일수록 공유하고 루트에 가깝게 위치  
   절대 기존 데이터베이스보다 크지 않다.  
   
<br>  

**FP-growth가 Apriori보다 빠르다.**  
Why?  
- Divide and conquer : 전체를 disjoint한 부분으로 나눈다.  
- candidate generation이 없다.    
- compressed database : FP-tree structure  
- 데이터베이스 스캔 2번     
  1st scan : to find 1 frequent itemset  
  2nd scan : to construct FP-tree
- 기본적인 연산  
  local frequent items 세고, sub FP-tree 생성하는 것  

<br>  

### 3. Vertical data format approach (Charm)     
vertical format : transaction마다 등장하는 itemset을 나열한 horizontal format과 달리 itemset마다 transaction id를 나열하는 형태   
t(AB) = {T11, T25, ...}  
<br>  

**순서**  
1) horizontal -> vertical format으로 바꾸기 위해 dataset을 scan한다.(item 수가 transaction수보다 적기 때문에 쉽다. )    
2) k=1 부터 frequent k-itemsets로 부터 (k+1)-itemsets의 후보를 만든다.(tid-sets끼리 intersection하고, apriori 알고리즘 이용)  
A,B가 frequent하고 t(A) = {T1, T2, T3, ...} 이고, t(B) = {T1, T3, T4, ...}이면 t(AB) = {T1, T3, ...} 이 되고 minSup가 넘으면 (k+1)-itemsets에 포함된다.  
3) frequent itemsets이 없을 때까지 반복한다.  
<br>  

**장점**  
* (k+1)-itemsets의 support를 계산하기 위해 database를 스캔하지 않아도 된다.  
   하지만 intersection에 많은 시간과 공간이 필요하다. 
   -> diffset technique를 이용한다. 두 아이템셋이 등장하는 transaction id를 비교하여 차집합만 저장  

<br><br>  

## Mining various kinds of association rules  
<br>  

### 1. Mining multilevel association  
: items가 계층(level)을 형성하는 경우! 계층이 낮을 수록 낮은 support value를 사용하는 것이 좋다.  
: 다른 계층임에도 같은 support를 사용하는 경우, 계층이 낮을수록 association rule에 포함되기 힘들어지고, 계층이 높을수록 association rule에 포함되기 쉽다.  
ex) Milk(minSup=5%), 2% Milk(minSup=3%), skimmed Milk(minSup=3%)  

<br>    
  
**Redundancy Filtering**  
: ancestor가 이미 그 rule를 나타내기 때문에 descendent rule은 불필요하다.  


milk => wheat bread (support=8%, confidence=70%)  
2% milk => wheat bread (support=2%, confidence=72%)  



-> 첫번째 룰은 두번째 룰의 ancestor  
-> descendent rule은  
  descendent의 support가 ancestor의 support값과 비교하여 기대하는 값과 비슷할 때,  
  descendent의 confidence값이 ancestor의 confidence 와 비슷할 때,  
  'redundant' 하다. 
<br>  


### 2. Mining multidimensional association   
<br>  

**- Single-dimensional rules**  
: having 1 dimension or 1 predicate  
buys(X, "milk") => buys(X, "bread") *buys 하나만 씀*   



**- Multi-dimensional rules**  
: having >=2 dimensions or predicates   

+ inter-dimension association rules  *반복되지않는 predicates*   
  age(X, "19-25") ^ occupation(X, "student") => buys(X, "coke")   
  
+ hybrid-dimension association rules *반복되는 predicates*   
  age(X, "19-25") ^ buys(X, "popcorn") => buys(X, "coke")   
  
<br>  

### 3. Mining quantitative association  

<br>  

**Attribute Types**   
 "19-25", "popcorn", "coke" => attributes의 value  
 

 - Categorical Attributes  
   -> value가 유한하고 value 사이에 순서가 없다.    
 - Quantitative Attributes  
   -> 수치이며 value 사이에 암시된 순서가 있다.    
   -> 이산화하거나 클러스터링 작업이 필요  

**Techniques**  
> numerical attributes를 다루는 방법  

- Static discretization based on predefined concept hierarchies   
  : data cube methods  
  -> numeric values는 range로 바꾼다.  
  -> k-predicate sets는 k,k+1의 table scan이 필요하다.  
     3개의 predicate이 있는 경우 3,4번 스캔 
  
- Dynamic discretization based on data distribution  
  : quantitative rules  
  인접한 association rule을 함쳐서 나타낸다. -> 30-40, 40-50을 합쳐서 동적으로 30-50으로.    
  예를 들어, 2D grid를 이용하여 association rule을 만들어보면 2D quantitative association rule은 아래와 같다.   
  A quan1 ^ A quan2 => A cat  
  -> confidence, support가 threshold보다 높아야 한다.  
  
- Clustering  
  : distance-based association  
  

### 4. Mining interesting correlation patterns  
언급 안 함.  

<br><br>  

## From association mining to correlation analysis   
기존 support, confidence는 상관관계를 나타내는 데에 좋은 measure가 아니다.  
예를 들어, 85%의 손님이 milk를 산다면 아래 문장은 오해의 소지가 있다.   
> buy walnuts => buy milk (sup=1%, conf=80%)  
conf는 walnuts를 산 사람이 milk를 살 확률인데, 80% < 85% 이면, 오히려 적게 사는 것.  

<br>  

따라서, correlation을 잘 드러낼 수 있는 또 다른 Measure는 무엇일까?  
아래 3가지의 값이 클수록 서로 연관성이 높은 것.  


### 1. lift  
lift = P(AUB)/P(A)P(B)  

### 2. Cosine  
Cosine = P(AUB)/root(P(A)P(B))  
lift와 비교 : total number of transaction이 동일하게 분모와 분자의 분모에 위치하게 된다. => total number of transaction에 독립  

### 3. all_conf  
all_conf = sup(X)/max_item_sup(X)  
X는 itemset이고, X 중에서 가장 support가 큰 값을 가진 item의 support 값이 분모   

<br><br>
## Constraint-based association mining  
*database에 있는 모든 pattern을 찾는 것은 비현실적! 사용자가 원하는 방향으로 mining을 진행할 수 있어야 한다.  


### 1. Concept  


Constraint-based mining은  
- User flexibility : 무엇을 mining 할지 constraints를 준다.  
- System optimization : 효과적으로 mining 하기 위해서 constraints를 파악한다.  

Constrained Mining vs Other Operations
  

### 2. Constraints in Data Mining    


- Knowledge type constraint  
  : 내가 원하는 것이 분류일 수도 있고, 클러스터링 일수도 있고 등등 원하는 것을 limit한다.  
  classification, association, clustering etc.  
  
- Data constraint  
  : sql과 비슷한 쿼리 사용   
  상점에서 함께 팔린 물건의 쌍을 찾아라와 같이.  
 
- Dimension/level constraint  
  : attribute 과 관련된 개념!  
  모든 애트리뷰트를 고려하는 것이 아니라 몇 개만 고려  
  -> region, price, brand, customer category  
  
- Interestingness constraint  
  : association rule mining 에서 배움  
  min support, min confidence에 대한 constraint 제시  
  

### 3. Constrained Mining vs Other Operations  

**Constrained Mining vs Constrained-based search  

- 공통점 : search space를 줄이는 목적  
- 차이점 : 전자는 constraints를 만족하는 모든 패턴을 찾고, 후자는 constraints를 만족하는 답을 찾기만 하면 된다.  


**Constrained Mining vs query processing in DBMS  

- 공통점 : 해당 조건에 맞는 모든 답을 찾는것(전자는 patterns, 후자는 tuples)  

### 4. Constraint Pushing  

- Anti-Monotonicity  
: itemset S가 constraint에 성립하지 않으면 S의 superset도 constraint에 성립하지 않는다.  

> ex. sum(S.Price)<=v is anti-monotone  
      sum(S.Price)>=v is non anti-monotone  
      range(S.profit)<=15 is anti-monotone  
  
  
- Monotonicity  
: itemset S가 constraint에 성립하면 S의 superset도 constraint에 성립한다.  

> ex. sum(S.Price)>=v is monotone  
      min(S.Price)<=v is monotone  
      range(S.profit)>=15 is monotone  


- Succinctness  
: itemset A1이 constraint C를 만족하면, C를 만족하는 어떤 집합 S는 A1에 기반해서 간단히 구해질 수 있다.  
=> 어떤 특정 아이템으로 C constraint를 만족한다.  


장점 : transaction database를 보지 않아도 itemset S가 어떤 item들을 선택했는지에 따라 constraint C를 만족하는지를 결정할 수 있다.  


Optimization : 만약 C가 succinct하면 C는 pre-counting pushable 하다.  
-> candidate-generation time에 basic elements가 포함되어있는지만 확인하면 해당 constraint를 만족하는지 확인할 수 있기 때문.   

> ex. min(S.Price)<=v is succinct  
      sum(S.Price)>=v is not succinct  
      
### 5. Converting "Tough" Constraints  
: tough constraints를 anti-monotone이나 monotone으로 바꾼다.  

> ex. avg(S.profit)>=25  

아이템을 감소하는 순서대로 정렬하면 superset은 뒤에 있는 더 작은 item이 들어오도록 하면,  
해당 식은 anti-monotone 으로 바뀐다.  


<br>  

## Summary  

- Frequent pattern mining - an important task in data mining  

- Scalable frequent pattern mining methods  
  > Apriori(Candidate generation & test)  
    Projection-based(FPgrowth, CLOSET+, ...)  
    Vertical format approach(CHARM, ...)  
    
- Mining a variety of rules and interesting patterns  

- Constraint-based mining  
 
- Extensions and applications  
      


