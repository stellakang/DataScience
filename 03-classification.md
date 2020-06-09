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
  
C4.5, K-Means, SVM, Apriori, EM, PageRank, AdaBoost, kNN, Naive Bayes, CART  

### 8. Major issues in data mining  
- Mining methodology: mining 방법론으로 성능이나 패턴 평가 등등 포함    
- User interaction: 유저가 data mining 시스템과 잘 상호작용할 수 있도록  
- Applications and social impacts: 일반적인 데이터->특정 도메인, 데이터 보안 등 신경쓰기  



## What is classification? What is prediction?  
: credit approval, target marketing, medical diagnosis, fraud detection 등에 활용된다.  
  
### 1. Classification  
: categorical class labels를 예측한다.  
: 트레이닝셋을 학습시켜 모델을 구성하고 이를 이용하여 새로운 데이터를 분류한다.  


**Model Construction**  
- 목표: 클래스 라벨이 주어진 트레이닝 데이터를 이용하여 학습시킨다.  
  - 모델: 학습 결과의 모델로 classification rules, decision trees, networks, or mathematical formulae로 나타낼 수 있다. 이후에 이 모델을 이용하여 새로운 샘플 데이터에 대한 결과를 가져온다.   

**Accuracy Evaluation**  
- 목표: 모델의 정확도를 평가한다.  
- 테스트 데이터: 트레이닝 데이터와 유사하게 클래스 라벨을 가지고 있다.  
- 모델을 통해 나온 결과와 실제 클래스 라벨을 비교하여 정확도를 계산한다.  
- 테스트셋과 트레이닝셋은 서로 겹치지 않아야 오버피팅이 발생하지 않는다.  

cf. Supervised vs. Unsupervised Learning  
- Supervised Learning(classification): 트레이닝셋은 라벨을 포함하며 이를 학습시켜 새로운 데이터를 분류한다.     
- Unsupervised Learning(clustering): 트레이닝셋의 라벨이 주어지지않고 데이터의 클러스터를 형성한다.    

### 2. Prediction
: 연속적인 값을 가진 함수의 모델을 구성하고 이를 이용하여 모르거나 잃어버린 값을 예측한다.   


## Issues regarding classification and prediction  


### 1. Issues : Data Preparation  
- Data cleaing: 노이즈가있거나 값이 비어있는 데이터를 줄이기 위한 전처리    
- Relevance analysis: feature selection(필요한 애트리뷰트만 남긴다.)    
- Data transformation: generalize, normalize data  

### 2. Issues : Evaluating Classification Methods  
- Accuracy  
  classifier accuracy: 클래스 라벨을 얼마나 잘 분류하는지  
  predictor accuracy: 애트리뷰트의 값을 얼마나 정확히 예측하는지  
  
- Speed  
  training time/ classification, prediction time  

- Robustness: 노이즈나 비어있는 값을 다루는 능력  

- Scalability: 디스크에 있는 많은 데이터에 대한 효율성  

- Interpretability: 뉴럴 네트워크는 어떻게 그러한 분류 결과가 나왔는지 이유를 잘 말해주지 못하므로 이 특성이 낮다.  
  -> 모델에 대한 이해도  

- 이 외에도 decision tree size, compactness of classification rules 등등  

## Classification by decision tree induction  


### 1. Algorithm  
: 'greedy algorithm'이며, 'top-down', 'recursive', 'divide-and-conquer' 방식으로 decision tree를 구성한다.  

1) 모든 트레이닝 샘플이 루트 노드에 있다. - 다른 에지나 노드 존재 안 함.  
2) 애트리뷰트는 categorical 하다고 가정한다. - 연속적인 값이면 범위 나누어서 분할해야 한다.  
3) 샘플들은 정해진 test attributes에 따라 재귀적으로 나누어진다.  
4) 해당 노드에서 '모든 샘플이 같은 클래스 라벨에 속하거나', '샘플을 나눌 수 있는 애트리뷰트가 더 이상 존재하지 않는  
   경우(더 많은 수의 클래스 라벨로 분류)', '샘플이 없는 경우' 더 이상 진행을 멈춘다.  

### 2. Test Attribute Selection - Attribute Selection Measure  
그룹을 나눌 때, 좀 더 클래스 라벨이 비슷한 것끼리 잘 나누는 애트리뷰트를 선택한다.  

- Information Gain  
  - 가장 높은 information gain을 얻는 테스트 애트리뷰트를 선택한다.  
  - 엔트로피(expected information):  
    Info(D)=-sum((pi)log2(pi)) 모든 클래스 라벨마다 전체 튜플 중 그 클래스라벨의 확률(=pi)을 대입하여 값을 구한다.  
    더 다양할수록 큰 엔트로피 값을 갖는다.  
    
  - A 애트리뷰트를 이용하여 D를 v개로 partition했을 떄 엔트로피    
    InfoA(D)=sum((Dj/D)xInfo(Dj)) 모든 v개의 partition마다 엔트로피 구한 것의 weighted sum  
  
  - Information Gained  
    A 애트리뷰트로 partition했을 때  
    Gain(A) = Info(D) - InfoA(D)  
  
  - 더 다양할수록 값이 크니까 'Info(D)의 값은 크면서 InfoA(D)의 값은 작은' Gain값이 가장 큰 애트리뷰트를 선택한다.  
  
  - 만약 애트리뷰트가 연속적인 값을 갖는다면, 애트리뷰트 값에 따라 증가하는 순서대로 정렬하고  
    두 페어 사이의 중간 값들을 split point로 볼 수 있다.  
    엔트로피를 계산했을때 가장 엔트로피가 작은(=information gain은 큰) split point가 best split point가 된다.  
    > split point는 애트리뷰트 값에 따라 나눈 것이므로 클래스 분포는 어떤 split point를 선택하느냐에 따라  
      비슷한 것끼리 나누어져있을수도 있고 너무 다른 클래스끼리 분류되어있을 수도 있다.  
      
    > binary partition이 아닌 n-ary partition도 가능하지만 combinatorial number of partition만큼 엔트로피를 계산하기 때문에  
      데이터가 너무 많으면 많은 엔트로피 계산이 수반되어 성능에 문제가 생긴다.  
      
  - 단점: value 값이 많은 애트리뷰트의 경우 information gain이 커진다.  
      
- Gain Ratio  
  - 등장 배경: Information gain은 애트리뷰트 value의 수가 많을수록 커지는 경향이 있다.  
    -> C4.5(well known classifier)는 gain ratio를 사용하여 이 문제를 해결함.  
  - GainRatio(A) = Gain(A)/SplitInfo(A)  
    SplitInfoA(D) = sum(-(|Dj|/|D|)xlog2(|Dj|/|D|))  
    여기서 splitinfoA는 애트리뷰트에 의해 나누어진 확률, 클래스라벨x  
  - Gain Ratio가 가장 큰 애트리뷰트가 선정된다.  
    
  - 단점: 불균형이 심한 애트리뷰트를 선택하기 쉬워진다.   
  
- Gini Index  
  - gini(D) = 1-sum(pj^2)  
    여기서 pj는 클래스라벨에 대한 확률  
    giniA(D) = (|D1|/|D|)gini(D1)+(|D2|/|D|)gini(D2)  
    여기서 A 애트리뷰트는 binary partition을 가정     
    
    
    Reduction in impurity:  
    delta gini(A) = gini(D)-giniA(D)  
    
 - 가장 'reduction in impurity'가 큰 애트리뷰트를 선택한다.  
   binary partition: 모든 split point 중에서 가장 giniA(D)가 작은 값의 지점을 고려해야 함.   
   어떤 애트리뷰트의 값이 low, medium, high가 있으면 low, medium/high로 나누거나, low/medium,high로 나눈다.  
 
 - 단점: 클래스 수가 많을수록 계산하기 어려워진다, partition이 균등하게 이루어지는 애트리뷰트를 선호한다.  
   
   
     

### 3. Overfitting  

- Overfitting  
: decision tree에서 트레이닝데이터 학습시키는 과정에서 발생할 수 있음 -> 각 브랜치에 하나의 튜플 있는 경우 
  - problem  
    : 너무 많은 브랜치가 있다보니 노이즈나 아웃라이어 때문에 다른 경우가 발생할 수 있다.  
    : 새로운 데이터에 대해서 낮은 정확도를 보인다.       

- Tree pruning  
: to avoid overfitting  

  - Prepruning  
    : goodness measure이 일정 값으로 떨어지면 더 이상 브랜치를 생성하지 않는다.  
    : 적당한 임계값을 정하기 어렵다.  
    
    
  - Postpruning  
    : pruned tree를 하나씩 본다음에 트레이닝 데이터 말고 다른 데이터로 정확도가 가장 높은 tree를 고른다.  


### 4. Why decision tree in data mining  

- classification in large databases  
  - unknown data를 정확하게 분류하는 것이 목적  
  - scalability: performance에 대한 것으로 데이터가 너무 많으면 디스크에 존재하게 된다.  

- Why decision tree induction in data mining?  
  - 상대적으로 학습 속도가 빠르다.  
  - decision tree => classification rule로 생성 가능하다.  
  - disk, ssd에 있는 데이터를 sql query로 접근할 수 있다.  
  - 다른 classification 방법과 정확도를 비교할 수 있다.  
  

### 5. Rule extraction from a Decision Tree  

- rule이 decision tree 보다 이해하기 쉽다.  
- rule의 갯수 = root에서 leaf까지의 갯수  
- 여러 노드를 거쳐서 분류할 때 각각 애트리뷰트와 그 값의 쌍은 교집합으로 연결된다.  
- tuple은 단 하나의 path만 지나친다. : 서로 배타적이고 철저하다.  


## Bayesian classification  

### 1. Why bayesian classification?  
- 통계적인 classifier: 확률을 기반으로 분류하며 'Bayes' theorem'을 기반으로 한다.  
- Performance: naive bayesian classifier은 decision tree와 neural network와 비교할 만한 성능을 가진다.  
- Incremental: 기존 데이터에 추가적인 데이터를 학습시키기 용이하다. 데이터를 추가한다고 해서 전체 데이터를 다시 학습시킬 필요 없다.  
- Standard: 최적의 답의 표준을 제공한다.  

### 2. Bayesian Theorem: Basics  
- X는 데이터 샘플이며 클래스 라벨이 알려져 있지 않다.  
- H는 'X가 class C에 속한다'는 가설이다.  
- X가 주어졌을 때, 모든 클래스에 대해 P(H|X)의 확률이 가장 높은 클래스로 분류한다.  

- 확률 정보 
  - P(H) (prior probability-사전확률)  
    - The initial probability(X와 독립)  
    - X가 컴퓨터를 살 확률 등등  
  - P(X)  
    - X 데이터가 발생할 확률  
  - P(X|H) (posteriori probability)  
    - H라는 가설이 주어졌을때, X라는 데이터를 가질 확률
    - 예를들어, X가 컴퓨터를 산다고 할 때, X의 수입이 31-40일 확률  

- Conditional probability  
  - P(X|H)=P(X inter H)/P(H)  
  - P(H|X)=P(X inter H)/P(X)  
  - P(X inter H)=P(H|X)xP(X)=P(X|H)xP(H)  
  
- Bayesian Theorem  
  - P(H|X)=P(X|H)P(H)/P(X)  

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






