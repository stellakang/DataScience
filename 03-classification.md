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
  - X 데이터와 사후 확률 P(X|H)가 주어졌을때, 아래 식을 따른다.  
  - P(H|X)=P(X|H)P(H)/P(X)  
  - likelihood(우도) = posteriori(사후확률) * prior(사전확률)/evidence  
  - 모든 클래스 중에서 P(Ci|X)가 가장 큰 값을 가지는 클래스로 분류한다.  
  - 실질적으로 많은 갯수에 대해서 확률을 다 알아야 하니까 computational cost가 많이 든다. 

### 3. Naive Bayesian Classifier  
: bayes theorem을 계산할 때, P(X)는 상수값이니까 분자만 계산하면 되는데 이 값이 너무 computational cost가 많이 드니까   애트리뷰트끼리 다 독립이라고 생각하고 계산하기  

- P(X|Ci)=P(x1|Ci)xP(x2|Ci)x...xP(xn|Ci) 로 계산하면 계산량을 많이 줄일 수 있다.  
  - 만약 애트리뷰트가 categorical한 경우, P(xk|Ci)는 (애트리뷰트값이 xk인 튜플 수)/(Ci에 속하는 튜플 수)  
  - 만약 애트리뷰트가 continuous-valued인 경우, 평균과 표준편차 값을 가지고 가우시안 분포를 따른다고 보고 계산한다.  
    평균=class Ci의 평균, 표준편차=class Ci의 표준편차  
    
- Advantages  
  - 구현하기 쉽고 데이터가 늘어나면 기존 모델에 새로운 데이터 추가하면 된다.  
  - 좋은 결과를 가져온다.  
  
- Disadvantages  
  - 애트리뷰트끼리 독립적이라는 추정을 기반으로 하기 때문에 이 가정이 맞지 않는 경우 정확도 손실이 생긴다.  
  - 실질적으로 애트리뷰트끼리는 의존도를 가짐. 나이랑 당뇨병이랑 연관이 있듯이!  
    -> 이 의존도를 어떻게 해야하나? Bayesian Belief Networks (여기서 다루지 않는다.)  
 

### 4. Avoiding the 0-Probability Problem  

- 조건부 확률중에 하나라도 0인 값이 있으면 해당 클래스에 대한 확률은 0이 되는 문제가 발생   
- **Solution** Laplacian correction 사용 : 모든 애트리뷰트의 값마다(partition) 1을 더해준다.  
  예를 들어, Prob(income=low)의 분모에는 애트리뷰트의 수만큼 더해지고 분자에는 1이 더해질 것  

## Rule-based classification  

### IF-THEN Rules    
: knowledge를 IF-THEN 형태로 표현한다.  
: If 부분은 antecedent/precondition, Then 부분은 rule consequent이라고 한다.  

- Assessment of a Rule <*Rule R에 대한 평가 기준*>      
  - coverage: R로 분류가 가능한 것의 확률. Ncovers/|D|  
  - accuracy: 분류가 가능한 것 중에서 맞게 분류되는 확률. Ncorrect/Ncovers  
  
- Conflict Resolution  
  : 만약, 여러 룰에 다 해당되는 경우, conflict resolution 필요  
  - size ordering: antecedent에서 애트리뷰트의 갯수가 많은, 가장 tough한 rule을 고른다.  
  - class-based ordering: 클래스마다 빈도수를 계산하거나 잘못 분류된 cost 등으로 결정한다.    
  - rule-based ordering: 전문가에 의해 기준을 정해서 우선순위를 정한다.    


## Associative Classification  

- Associative classification  
  - association rules는 분류에 사용된다.  
  - frequent pattern과 클래스 라벨 간에 결합력이 큰 것을 찾는다.  
  - 형태  
    : p1^p2...^pi -> "Aclass=C"(conf, sup)  
  - decision tree는 룰이 exclusive 하지만, associative classification은 룰이 not exclusive하다.  
    튜플이 주어지면 하나 이상의 룰에 배치된다.  
    
- Why effective?  
  - 많은 애트리뷰트 중에서 가장 높은 결합력을 가진 것을 탐색한다.  
  - C4.5보다 더 정확하다고 알려져있다.  


## Lazy learners  

### 1. Lazy vs Eager Learning  
- Eager learning
  : 이전에 다루어졌던 방식 
  - 트레이닝셋이 주어졌을때, 새로운 테스트 튜플을 받기 전에 분류 모델을 형성한다.  
    > 바로 테스트셋이 오면 분류할 수 있도록!   
  - 테스트샘플은 모델의 구축에 영향을 미치지 못한다.  
- Lazy learning  
  - instance-based learning, lazy evaluation    
  - 트레이닝셋이 주어졌을때, 그냥 저장해두고 테스트 튜플이 주어질 때까지 기다린다.  
  - 테스트 샘플에 기반해 뽑힌 데이터로 local model을 만들고 inference 한다.  
  - 트레이닝에는 시간이 더 적게 걸리고 예측할 때에 더 많이 걸린다.  
  - typical example: knn approach  

### 2. Accuracy  
- eager method는 전체 데이터를 다 다룰 수 있는 하나의 모델(hypothesis)를 만들어야 한다.  
- lazy method는 많은 local linear function들을 이용한다.  

### Lazy Learning example : KNN  
- 모든 인스턴스들은 n차원 공간에 대응한다.(n 애트리뷰트가 있을 때)  
  -> dist(X1, X2)가 공간에서 정의된다.  
- 테스트 샘플이 주어지면, 거리가 가장 가까운 k개의 샘플을 가져오고   
  그 중에서 다수의 그룹의 클래스로 분류된다.  

  
## Prediction  

### 1. What is Prediction?  

- classification과 비슷하다.  
  - 모델을 찾고 주어진 인풋에 대해 연속적인 값을 예측한다.  
  
- classification과 다른 점  
  - classification은 categorical class label을 예측  
  - prediction은 continuous-valued function 모델을 이용하여 continuous space의 값을 예측하는 것  
  
- 주요 함수: regression  
  - 한개 이상의 독립변수와 종속변수 사이의 관계를 모델링한다.  

- Regression analysis  
  - linear and multiple regression  
  - non-linear regression  
  등등  

### 2. Linear Regression   

- Linear regression  
  - 1개의 독립변수 x와 종속변수 y를 포함한다.(linear function-선형함수)   
  - training  
    training data를 이용하여 가장 잘 맞는 직선을 찾는다.  
    y = w1x + w0  

  - Least square method  
    y = w0 + w1x 직선 중 가장 잘 맞는 직선을 찾기 위한 방법  
    w0, w1을 찾기 위함.  
    실제값과 함수의 차이의 제곱이 최소가 되도록 하는 w0, w1  
    
    
    w1=sum((xi-avg(x))x(yi-avg(y)))/sum((xi-avg(x))^2)  
    w0=avg(y)-w1xavg(x)  

- Multiple linear regression  

  - 아까는 독립변수가 하나였는데 여기서는 하나 이상!  
    X=<x1,x2,x3,...,xn>: 독립변수(predictor variables)  
    y:종속변수(response variable)  
  - 만약 2-D data의 경우는 y=w0 + w1x1 + w2x2  
  - solutions  
    : least square method의 확장으로 SAS나 S-plus와 같은 도구 사용  
  

### 3. Nonlinear Regression   

- 어떤 nonlinear models는 다항 함수와 같은 형태로 나타날 수 있다.  
- polynomial regression model은 linear regression model로 바꿀 수 있다.  
  x2 = x^2, x3 = x^3  
  y = w0 + w1x + w2x2 + w3x3  

## Accuracy and error measure  

### 1. Classifier Accuracy Measures  

- Confusion matrix  
  |    | C1 | C2 | 
  | -- |:--:|:--:|
  | C1 |True positive|False negative|
  | C2 |False positive|True negative|  
  
  주로 찾아내야하는 질병, 사기 등을 positive로 둔다.  
  True, False: 실제 클래스와 분류한 결과의 일치 여부  
  positive, negative: 내가 분류한 결과가 positive인지 negative인지  
    
    
  Example.
  |    |buy_computer=yes|buy_computer=no|total|recognition(%)| 
  |:--:|:--:|:--:|:--:|:--:|
  |buy_computer=yes|6954|46|7000|99.34|
  |buy_computer=no|412|2588|3000|86.27|
  |total|7366|2634|100000|95.52|  
  
  - Accuracy of a classifier M, acc(M): 모델에 의해 제대로 분류될 확률  
    = (6954+2588)/100000  
  - Error rate of M = 1 - acc(M)  

- Accuracy Measures  
  - sensitivity(recall) = t-pos/pos 6954/7000   
  - specificity = t-neg/neg 2588/3000    
  - precision = t-pos/(t-pos+f-pos) 6954/(6954+412)  
  - accuracy = sensitivity x pos/(pos+neg) + specificity x neg/(pos+neg)  
    = t-pos/(pos+neg) + t-neg/(pos+neg) = (t-pos+t-neg)/(pos+neg)  
  
  > 차이 알기: sensitivity(재현율)는 암 걸린 사람들 중에 암 걸렸다고 판단한 사람들의 비율  
    precision(정밀도)은 암이라고 판단한 사람들 중에 진짜 암 걸린 사람들의 비율   
    재현율은 암환자 생각하고 정밀도는 스팸 생각하기!!!  
    
    
    - 암환자에게 암이 아니라고 예측한 경우는 치명적! => recall  
    - 스팸이라고 예측했는데 그 중에 정상 메일이 있는 경우는 치명적! => precision  
  

### 2. Predictor Error Measures  

- Measure predictor accuracy  
  예측값이 실제값보다 얼마나 멀리 떨어져있는가!  
  
- Loss function  
  실제 값과 예측된 값의 차이(=에러)를 측정한다.  
  Absolute error: |yi-yi'|  
  Squared error: (yi-yi')^2  
  
- Test error(generalization error)  
  : 테스트셋의 loss의 평균  
  
  - Mean absolute error: sum(|yi-yi'|)/d  
  - Mean squared error: sum((yi-yi')^2)/d  
  - Relative absolute error: sum(|yi-yi'|)/sum(|yi-avg(y)|)  
  - Relative squared error: sum((yi-yi')^2)/sum((yi-avg(y))^2)  
  
    
  -> mean squared error는 아웃라이어를 더 크게 측정한다.   
  -> square root mean squared error(mean squared error에 루트 씌운거)와 square root relative squared error(relative squared error에 루트 씌운거)가 자주 쓰인다.  
  



### 3. Evaluating the Accuracy of a Classifier or Predictor  

- Holdout Method  
  - 주어진 데이터가 랜덤하게 training set, test set 으로 분리된다.  
  - 랜덤 샘플링: holdout의 변형  
    -> holdout을 k번 반복한다.  
    -> 정확도는 얻어진 k개의 평균  

- Cross Validation  
  - k-fold, k=10이 널리 쓰임  
  - 랜덤하게 데이터를 동일하게 k개로 나눈다.(서로 교집합 없이)  
  - i-th iteration에는 Di를 테스트셋으로 하고 나머지는 트레이닝셋으로 한다.  

- Leave-one-out  
  - 적은 데이터를 위한, cross-validation의 특별한 케이스  
  - k = # of tuples -> k를 데이터 수만큼  

- Stratified cross-validation  
  - cross-validation의 특별한 케이스  
  - 각 fold의 클래스 분포가 같아지도록 분배한다.  
  - 예를 들어, positive=70%, negative=30% 이면, 각 fold의 데이터들도 이 비율을 이루도록 분배한다.  

- Bootstrap  
  - 작은 데이터셋인 경우 필요하다. (불충분한 트레이닝 샘플)  
  - 전체 데이터셋에서 트레이닝 샘플을 골라낼 때, 한 번 골랐던 샘플도 다시 선택될 수 있도록 한다.  
  - .632 bootstrap: 가장 흔한 bootstrap 방법  
    - 데이터셋이 d샘플로 이루어져있으면, d번 샘플되고 한 번 골라졌던 것도 다시 고를 수 있다.  
    - 전체 데이터에서 결과적으로 뽑히지 않은 것은 테스트셋으로 분류한다.  
    - 대략 전체 데이터의 63.2%가 트레이닝셋으로 분류되고 36.8%가 테스트셋으로 분류된다.  
    - 샘플링하는 과정을 k번 반복하며 모델의 정확도는 i=1~k에 대하여   
      acc(M) = sum(0.632x(model Mi acc of testset) + 0.368x(model Mi acc of trainset))  


## Ensemble Methods  

### 1. Concepts  
- 여러 모델들의 조합으로 정확도를 높인다.  
- k개의 학습된 모델을 결합하여 개선된 M' 모델을 생성한다.  
- 잘 알려진 앙상블 메소드  
  - Bagging: 여러 분류기의 예측값의 평균  
  - Boosting: 여러 분류기마다 가중치를 매긴 결과    
  - Ensemble: 다른 종류의 분류기들을 결합   

### 2. Bagging: Bootstrap Aggregation    

- "의사들의 가장 많은 투표를 차지한 진단을 내린다"  

- Training  
  - bootstrap 방식으로 테스트셋을 정한다.  
    d개의 튜플을 중복허용해서 d개 뽑는다.  
  - 각 트레이닝셋마다 분류모델을 학습시킨다.  

- Classification  
  - 각 분류기 Mi는 예측 클래스를 리턴한다.  
  - bagged classifier M'는 각 분류기의 결과값을 모아서 가장 많은 클래스를 리턴한다.  
  
- Prediction  
  - 테스트튜플의 각 예측값의 평균값을 리턴한다.  
  
- Accuracy  
  - 하나의 분류기보다 더 나을 때가 많다.  
  - 노이즈 데이터에 대해서 상당히 나쁘지 않다.  
  - prediction, classification에서 개선된 정확도를 보임  


### 3. Boosting  

- "이전 진단 기록을 바탕으로 더 정확한 진단을 하는 의사에게 높은 가중치를 주어 진단을 내린다"  
- 진행 과정  
  - 각 트레이닝 튜플에 가중치가 할당된다.(처음엔 weight가 모두 같은데 학습해가면서 달라진다.)    
  - k개의 분류기가 학습된다.  
  - 분류기 Mi가 학습된 후, Mi+1을 학습시킬 떄에는 이전 Mi에서 잘못 분류된 트레이닝 튜플에 더 큰 가중치를 부여한다.  
    -> 그럼 더 트레이닝 샘플로 뽑힐 가능성이 높아진다.  
  - 최종 M'은 가중치(=각 분류기의 정확도)가 반영된 각 분류기의 결과를 결합하여 나타낸다.   




