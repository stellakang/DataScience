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


- **Max-patterns**   
itemset X is a max-pattern if X is frequent and there exists no frequent super-pattern Y    
> 더 늘릴게 없어!! frequent pattern 이고 frequent super pattern이 없음!!     
                 
<br><br>       
       
## Efficient and scalable frequent itemset mining methods   
*Frequent pattern을 찾아내는 일반적인 방법 3가지!*  
<br>  

**1. Apriori**    
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
  
<br>  

**- Reduce the number of transaction database scans**   
<br>  

  **a. Partition**    
     scan1 : DB를 k개로 나누면 각 local databases(=partition)에서 local minSup (=minSup/k)이 넘는 local frequent patterns 찾는다.  
     scan2 : local frequent patterns 이더라도 global frequent patterns는 아닐 수 있기 때문에 확인  
     이때, partition은 각각 메인메모리에 있음  
<br>  

  **b. Sampling for Frequent Patterns**    
     **<기존 sampling>**  
     original database -- sample --> SDB -- apriori --> local frequent pattern(minSup은 더 작은 값 사용)  
     문제점 : local frequent는 실제로 frequent patterns가 아닐 수 있고 전체 DB에서 frequent patterns가 빠졌을 수 있다.  
     **<보완한 sampling>**   
     **scan1** -> S, NB에서 frequent itemsets 찾기  
     S : local frequent pattern  
     NB : S에는 없지만, S에 모든 subsets가 있는 itemsets를 포함시킨다.(빠진 frequent pattern을 찾기 위해)  
     **scan2** -> NB에서 frequent itemset으로 포함되면서 frequent patterns가 될 수 있는 것들을 위함  
<br>  

  **c. DIC**  
     같은 스캔에서 길이가 다른 itemsets가 후보로 들어있다.  
     a,d가 frequent이면 2-itemsets 탐색하기 시작, bcd의 모든 subsets가 frequent이면 bcd 탐색 시작  

<br>  

**- Shrink the number of candidates**   
  a. DHP  
     DB 스캔 한 번 할 때, k-itemsets의 support를 계산하는 동시에 (k+1)-itemsets를 위한 해시테이블을 만든다.  
     -> hash table의 각 row는 hash bucket을 의미하며 hash값이 같은 itemset끼리 같은 hash bucket에 위치하도록 count
     -> hash bucket count가 minSup보다 작으면 frequent pattern에서 제외  
     -> candidate를 줄이는데 효과적   
     
**- Facilitate support counting of candidates**     


<br>  

**2. Frequent pattern growth (FPgrowth)**    
: Mining Frequent Patterns Without Candidate Generation  
: FP-tree를 기반으로 한다.  
<br>  

순서  
1) DB를 스캔하고, frequent 1-itemset 찾기  
2) f-list 만들기 : frequent item의 frequency가 감소하는 순서대로 정렬  
   F-list = f(4) - c(4) - a(3) - b(3) - m(3) - p(3)  
3) DB를 다시 스캔해서 FP-tree 만들기  
   root는 {}로 비워두고, 각 transaction 마다 frequent items를 정렬시켜 tree에 이어붙인다.    
   이때, 이미 동일한 브랜치가 있으면 count를 증가시키고 없으면 브랜치를 새로 만든다. f:3 이런식으로 노드 표기  
   frequent 1-item과 frequency가 적혀있는 header table에 시작점부터 존재하는 item까지 이어준다.  
   
<br>  
장점       
1) completeness = loseless information   
   모든 frequent pattern 포함한다.  
2) compactness = remove irrelevant info   
   더 빈도가 높은 item일수록 공유하고 루트에 가깝게 위치   
   절대 기존 데이터베이스보다 크지 않다.  
<br>  


<br>  

**3. Vertical data format approach (Charm)**  

<br><br>  

## Mining various kinds of association rules  

<br><br>  

## From association mining to correlation analysis  

<br><br>
## Constraint-based association mining  

