# Mining Frequent Patterns, Association and Correlations  

## Basic Concepts and a road map  
>"상점에서 어떤 물건들이 주로 함께 구입되는지, 또는 물건이 구입되는 순서는?"  
>"이 약에 예민한 dna는 어떤 것인지?"  

### "데이터 안에 내재된 규칙을 찾기 위해 **Frequent Pattern Analysis** 를 한다!!"  

### 1. Frequent pattern  
  
= 데이터셋에서 자주 등장하는 패턴!     
a pattern(a set of items, subsequences, substructures ...) that occurs frequently in a data set  

### 2. Frequent Pattern Analysis 응용 분야      
Basket data analysis | cross-marketing | catalog design | sale campaign analysis | Web log analysis | DNA sequence analysis  
> 구매자 물품 목록을 가지고 분석하거나, 크로스 마케팅을 위해 소비자의 구매 형태를 고려하여 특정 물품을 추가로 판매하거나,   
선전을 목적으로 카탈로그를 디자인하거나 클릭 스트림을 가지고 분석하거나 DNA 분석하는 등등  

### 3. Frequent Pattern Analysis 가 중요한 이유  
 많은 data mining task의 토대가 된다.  
 -> 아래의 다양한 data mining task가 용이해진다.  
> Association, correlation, causality analysis  
Sequential, structural patterns  
Pattern analysis in spatiotemporal, multimedia, time-series and stream data  
Classification : associative classification  
Cluster analysis : frequent pattern-based clustering  
Semantic data compression  

### 4. Concepts  
**Association rule X -> Y**   
**support** : probability that a transaction contains X U Y  
> (아이템셋 X와 Y를 모두 포함하는 트랜잭션의 수)/(전체 트랜잭션의 수)  

**confidence** : conditional probability that a transaction having X also contains Y  
> (아이템셋 Y를 포함하는 트랜잭션의 수)/(X를 포함하는 트랜잭션의 수)  

**문제)**    
min sup = 50%, min conf = 50% 일때, 모든 association rules X -> Y를 찾아라.  
| Transaction-id | Items bought |
| -------- | :------: |
| 10 | A,B,D |
| 20 | A,C,D |
| 30 | A,D,E |
| 40 | B,E,F |
| 50 | B,C,D,E,F |   

**1) Frequent pattern**   
= min support 이상인 아이템셋,  
symmetric : AD가 frequent pattern <=> DA가 frequent pattern     
답 : { A:3, B:3, D:4, E:3, AD:3 }

**2) Association rules**  
답: 
A -> D (sup: 60%, conf: 100%)  
D -> A (sup: 60%, conf: 75%)  
  
## Efficient and scalable frequent itemset mining methods  

## Mining various kinds of association rules  

## From association mining to correlation analysis  

## Constraint-based association mining  

