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
  -  
  -  
- Hierarchical approach  
  -  
  -  
- Density-based approach  
  -  
  -  


### 2. Centroid, Radius, and Diameter of a cluster  

- Centroid  
- Radius  
- Diameter  


- Typical Alternatives to Calculate the Distance between Clusters  
  - Single link  
  - Complete link  
  - Average  
  - Centroid  
  - Medoid  
  

## Partitioning Methods  

### 1. Basic Concept  

-  
-  
- k는 주어져야 한다.  


### 2. The K-Means Clustering Method  

- Algorithm  
  - 
  - 
  - 
  - 
  - 
  

- Characteristics  
  - Strength  

  - Comment  

  - Weakness  


- Variations of the K-Means Method  

  - k-modes: Handling categorical data  
  
  - k-prototype: A mixture of categorical and numerical data   
  
  
- Problem  
  
  - outliers에 민감하다.  
  
  ==> K-medoids  
  


### 3. The K-Medoids Clustering Method  

- PAM  
  - Algorithm  
  
  - Problem  
    - 
    
    ==> CLARA  
  

- CLARA  
  -   
  - Strength  
  - Weakness  
  
  

## Hierarchical Methods  

### 1. Hierarchical Clustering  
:  
- agglomerative(AGNES)    
- divisive(DIANA)  

### 2. Advanced Hierarchical Clustering Method  
:  

- BIRCH  

- ROCK  

- CHAMELEON  

## Density-Based Methods   
:  

### 1. Basic Concepts  

  - Major features  
  - Several interesting studies  
    - DBSCAN  
    - OPTICS  
    - CLIQUE  
    
  - Two parameters  
    - Eps  
    - MinPts  
    
  - Directly density-reachable   
    :  
    -  
  
  - Density-reachable  
    :  
    -   
    
  - Density-connected  
  

### 2. DBSCAN  

-  
-  

- Algorithm  
  -  
  -  
  -  


### 3. OPTICS  

- Concepts  
  -  
  -  

- Process  



## Outlier Analysis  

### 1. What is Outlier Discovery  

-  
- Problem  
- Applications  
  -  
  -  
  -  
  -  
  

### 2. Outlier Discovery: Statistical Approaches  

- Use discordancy tests depending on  
  - 
  
  
- Drawbacks  
  - 
  

### 3. Outlier Discovery: Distance-Based Approach  

-  
-  
-  


