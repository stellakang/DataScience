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
- candidates 수가 많다.   
- support counting 하는 데에 업무량 많다.  

<br>  

**Improving Apriori**   
- Reduce the number of transaction database scans     
  a. Partition  
  
  b. Sampling for Frequent Patterns  
  
  c. DIC  

- Shrink the number of candidates   
  a. DHP  
  
- Facilitate support counting of candidates :   


<br>  

**2. Frequent pattern growth (FPgrowth)**    

<br>  

**3. Vertical data format approach (Charm)**  

<br><br>  

## Mining various kinds of association rules  

<br><br>  

## From association mining to correlation analysis  

<br><br>
## Constraint-based association mining  

