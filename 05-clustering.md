# Cluster Analysis  

## What is Cluster Analysis   

### 1. Cluster  
: data objects의 모임  


- 같은 클러스터 안에 있으면 서로 비슷하다.  
- 다른 클래스에 있으면 서로 다르다.  

### 2. Cluster Analysis  
:  

- Unsupervied learning  
- Typical applications  
  -  
  -  
  
- Applications  


## Quality and Requirements of Clustering  

- Quality: What is good clustering  

- Measure the Quality of Clustering  

- Requirements of Clustering in Data Mining  
  - 



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

-  
-  

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


