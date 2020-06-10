# Getting to know your Data  

## Data Objects and Attribute Types  

### 1. Types of Datasets.  
> 어떤 타입의 데이터셋이 있는지 알아야 전체 데이터를 잘 이해할 수 있다.  

- Record  
  - 애트리뷰트 값으로 이루어져있는 row  
  - Relational records(term-frequency vector), Transaction data  
  
- Graph and network   
  - Social or information networks  
  - world wide web  
  - molecular structures  
  
- Ordered  
  - video data: sequence of images  
  - temporal data: time-series  
  - sequential data: transaction sequences  
  - genetic sequence data  
  
- Spatial, image and multimedia  
  - spatial data: maps  
  - image data  
  - video data  

### 2. Important Characteristics of Data  

- Dimensionality  
  - curse of dimensionality  
    dimension이 너무 커지면 발생하는 문제  
    차원이 높아지면 데이터도 많이 필요하게 된다.  
    
- Sparsity  
  - density가 낮으면(sparse하면) 데이터를 분석하기 어렵다.  
  
- Resolution  
  
- Distribution  
  centrality, dispersion  

### 3. Data Objects  

- 데이터는 데이터 오브젝트들로 이루어져 있다.  
- sales database, medical database, university database 등등  
- 동의어: tuples, samples, examples, instances, data points, objects  
- 애트리뷰트들로 이루어져있다.    
- 데이터베이스 행 -> data objects, 열 -> attributes  
  
  
### 4. Attributes  
: 특정 데이터 오브젝트를 설명하는 특성  

- = dimensions, features, variables  
  

- Attribute Types
  - Nominal  
    - 값이 유한하다.  
    - ex. hair_color={black, blond, brown, grey, red, white}  
    
  - Binary  
    :2가지 상태(0,1)만 가지는 nominal attribute의 특별한 케이스  
    - Symmetric binary: 두가지 값이 동등한 중요성을 갖는 경우  
    - Asymmetric binary: 더 중요한 결과(질병)를 1로 둔다.  
    
  - Ordinal  
    - 순서가 의미가 있다.  
    - 두 값이 얼마나 떨어져있는지 그 규모를 알 수 없다.  
    - ex. size={small, medium, large}, scores={A0, A+, B0, B+...}  
    
  - Numeric  
    - Ratio-scaled  
      *무게나 길이, 돈*  
      zero-point가 존재한다.  
      임의의 값 사이에 규모가 얼마나 차이나는지 알 수 있다. -> 6kg은 3kg의 두배  
      
    - Interval-scaled   
      *온도나 달력 날짜*  
      동등한 사이즈의 유닛들 -> 연속적인 두 값의 차이를 알 수 있다!! ordinal과 다르게    
      값 사이에 순서가 있다.  
      진정한 zero-point가 존재하지 않는다. -> 0도는 온도가 없는 것이 아님   

- Discrete vs Continuous Attributes  

  - Discrete Attribute  
    - 유한하고 셀 수 있는 값들  
    - 우편번호, 단어 수 등등  
    - binary는 discrete attributes의 특별한 케이스  
     
  - Continuous Attribute  
    - 숫자로 나타내어지며 일반적으로 floating point, double로 표현된다.  
    - 온도, 높이, 무게 등등  
    
      
  
## Basic Statistical Descriptions of Data  
: To better understand the data  

- Data 분산 나타내는 특성  
  : median, max, min, quartiles, outliers, variance, etc.  
  
### 1. Measuring the Central tendency  
- Mean  
- Median  
- Mode  

- symmetric vs skewed data  


### 2. Measuring the Dispersion of Data  

1) Measurements    
- quartiles  
- Inter-quartile range  
- Five number summary  
- Boxplot  
- Outlier  
- Variance  
- Standard deviation  

2) Boxplot Analysis  
- Five-number summary  
- Boxplot  

3) Properties of Normal Distribution Curve  



## Data Visualization  

### 1. Boxplot  
### 2. Histogram  
### 3. Quantile plot  
### 4. Quantile-quantile plot  
### 5. Scatter plot  


## Measuring Data Similarity and Dissimilarity  

### 1. Similarity and Dissimilarity  

### 2. Data matrix and Dissimilarity matrix  

### 3. Proximity Measure  

  - Nominal Attributes  
  
  - Binary Attributes  
  
  - Numeric Attributes  
    
    - Minkowski distance  
    
  - Ordinal Attributes  
  
  - Mixed Type  
  
  
### 4. Standardizing Numeric Data    


### 5. Cosine Similarity  




