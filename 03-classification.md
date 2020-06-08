# Classification and Prediction  

## Data Mining Introduction  

### 1. Why Data Mining  
- Why Data Mining  
  : 데이터가 굉장히 많기 때문에 그 데이터 안에서 필요한 knowledge를 가져오는 것이 중요  
  
  
- Evolution of Sciences  
  **empirical science**(~1600): 실험 등을 통해 무언가를 찾아내는 '경험과학'  
  **theoretical science**(1600-1950): 이론이 중요하며 이를 통해 다른 실험을 이끌어낸다.  
  **computational science**(1950-1990): 시뮬레이션을 의미하며 이를 통해 많은 시간을 절약할 수 있다.  
  **data science**(1990-now): 많은 데이터가 등장하면서 이를 잘 관리하고 저장하며 새로운 정보를 얻는 것이 중요해졌다.  
  cf. big data era는 두가지 관점으로 이해 가능  
  : 1. database perspective - scalability, 2. data science perspective - real world 이해하는데 도움된다.   
  
  
- Evolution of Database Technology  
  **1960s** : 데이터가 없으니 '데이터 수집', '데이터베이스 생성', IMS and network DBMS  
  **1970s** : 관계형 데이터 모델, 관계형 DBMS 구현  
  **1980s** : 관계형 데이터 베이스에서 확장된 관계형 DBMS, 응용 중심 DBMS        
  **1990s** : 데이터 마이닝의 필요성이 생겨나고 data warehousing 등장      
  **2000s** : 데이터 마이닝과 응용  

### 2. What Is Data Mining  
= knowledge discovery from data  


Extraction of interesting(= non-trivial, implicit, previously unknown, potentially useful)  
patterns or knowledge from huge amount of data.  
> 많은 데이터 안에서 '중요하고 내포되어있고 알려지지 않았고 잠재적으로 유용한' 패턴이나 지식을 추출하는 것  
  단순한 탐색 같은 것은 데이터 마이닝이 아니다.  
  
  
Alternative names: knowledge discovery in databases(kdd), ...  


Why not Traditional Data Analysis?  
: 전통적 통계학 - 단순한 상황에서는 잘 작동  
  매우 많은 양의 데이터, 고차원의 데이터, 복잡한 데이터, 새롭고 정교한 애플리케이션이기 때문  



### 3. Knowledge Discovery Process  

**Databases**-(1)-**Data Warehouse**-(2)-**Task-relevant Data**-(3)-**Pattern Evaluation** - **Knowledge**  

(1) Data Integration & Data Cleaning  
Data Integration : 데이터베이스를 통합한다. -> Data warehouse(데이터베이스들의 데이터베이스, 데이터베이스의 스냅샷과 같음, non dynamic)  
Data Cleaning : data mining의 질을 높이기 위해 noise, missing data(inconsistency) 문제를 해결한다.   

(2) Selection  
Data warehouse에서 해당 작업과 관련된 데이터를 선택한다.  
데이터 마이닝은 일반적으로 data warehouse의 모두 사용하지 않는다.  

(3) Data Mining  
데이터 마이닝을 거쳐서 나온 것 중에서 pattern evaluation을 통해 몇 가지의 pattern을 고른다.  

### 4. Data mining and Business Intelligence  
위에 있을수록 높은 상위 계층  
|   계층   | 관련 유저 |  
| :-----: | :-----: |  
|**Decision Making**|End User|
|**Data Presentation**<br>*Visualization Techniques*|Business Analyst|  
|**Data Mining**<br>*Information Discovery*|Data Analyst|
|**Data Exploration**<br>*Querying, Reporting*||
|**Data Preprocessing/Integration, Data Warehouses**||
|**Data sources**|DBA|

### 5. Data Mining: Classification schemes  
  
- 데이터 마이닝 : classification schemes   
  1) Descriptive data mining : 현재 데이터에 대해 기술  
  2) Predictive data mining : 새로운 데이터에 대한 예측   

- Classification과 관련된 4가지 view  
  Data view : mining할 데이터 관점 (Data to be mined)  
  --> Data for mining: 데이터베이스 중심 데이터 집합(관계형 데이터베이스, 데이터웨어하우스, 트랜잭션 데이터베이스)/ advanced datasets and applications    
  
      
  Knowledge view : 탐색할 knowledge 관점 (Knowledge to be mined)  
  Method view : 활용할 technique 관점 (Techniques utilized)   
  Application view : 적용할 application 관점 (Applications adapted)  
  


### 6. Data mining functionality   

- Multidimensional concept description: Characterization and discrimination    
  많은 튜플을 몇 개로 줄여서 요약하고 튜플끼리 비교  
  

- Frequent patterns, association, correlation vs causality  

- Classification and Prediction  

- Cluster analysis  
  class label이 알려져있지 않음  

- Outlier analysis  

- Trend and evolution analysis  


### 7. Top-10 most popular data mining algorithms  
18 identified candidates  
C4.5, K-Means, SVM, Apriori, EM, PageRank, AdaBoost, kNN, Naive Bayes, CART  

### 8. Major issues in data mining  
- Mining methodology: mining 방법론으로 성능이나 패턴 평가 등등 포함    
- User interaction: 유저가 data mining 시스템과 잘 상호작용할 수 있도록  
- Applications and social impacts: 일반적인 데이터->특정 도메인, 데이터 보안 등 신경쓰기  



## What is classification? What is prediction?  

  
### 1. Classification  
:  


**Model Construction**  

**Model Usage**  

**Accuracy Evaluation**  

cf. Supervised vs. Unsupervised Learning  
- Supervised Learning   
- Unsupervised Learning  

### 2. Prediction
:  


## Issues regarding classification and prediction  


### 1. Issues : Data Preparation  

### 2. Issues : Evaluating Classification Methods  

## Classification by decision tree induction  


### 1. Algorithm  

### 2. Test Attribute Selection - Attribute Selection Measure  
- Information Gain  
- Gain Ratio  
- Gini Index  

### 3. Overfitting  

- Overfitting  
: 
problem = 

- Tree pruning  
: to avoid overfitting  
- Prepruning  
- Postpruning  

### 4. Why decision tree in data mining  


### 5. Rule extraction from a Decision Tree  


## Bayesian classification  

### 1. Why bayesian classification?  

### 2. Basics  

### 3. Naive Bayesian Classifier  

- Advantages  
- Disadvantages  

### 4. Avoiding the 0-Probability Problem  


## Rule-based classification  

### IF-THEN Rules  
- Representation  

- Assessment of a Rule  

- Conflict Resolution  


## Associative Classification  


## Lazy learners  

### 1. Lazy vs Eager Learning  

### 2. Accuracy  

### 3. Lazy Learner : Instance-Based Methods  

- k-nearest neighbor approach  

  
## Prediction  

### 1. What is Prediction?  

### 2. Linear Regression  

### 3. Nonlinear Regression  


## Accuracy and error measure  

### 1. Classifier Accuracy Measures  

### 2. Predictor Error Measures  

### 3. Evaluating the Accuracy of a Classifier or Predictor  

- Holdout Method  

- Cross Validation  

- Leave-one-out  

- Stratified cross-validation  

- Bootstrap  


## Ensemble Methods  

### 1. Concepts  

### 2. Bagging  

### 3. Boosting  






