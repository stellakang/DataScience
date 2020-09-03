# Data Preprocessing  

## Data preprocessing의 주요 task  
- Data cleaning  
- Data integration  
- Data reduction  
- Data transformation and data discretization  

### Missing data를 handle하는 방법  
- 해당 tuple을 지워버린다. -> 거의 모든 tuple의 class label이 missing인 경우 비효율적  
- unknown과 같은것으로 채워넣거나 평균으로 넣는다.  
- bayesian 이나 decision tree를 이용하여 값을 추정한다.  

### Noisy data를 handle하는 방법    
- 클러스터링으로 찾아낸다.  
- 컴퓨터로 걸러낸 후 사람이 확인  

## Data Integration  
### Redundancy handling  
- 불필요하게 중복된 데이터들을 핸들링하는 방법  

- Correlation analysis  
- Covariance analysis  

### Correlation analysis  
- 두 개의 애트리뷰트에 대해서 연관성을 확인  
- 카이검정을 통해 해당 값이 클수록 두 애트리뷰트는 연관되있음을 의미  
- nominal 데이터와 numeric 데이터에 대한 계산 방법은 서로 다르다.  
- 중요! 상관관계가 있다고 인과관계 의미하지 않는다.  

### Covariance  
- correlation과 유사  

## Data Reduction  
- dimensionality reduction  
- numerosity reduction  
- data compression  

### 1. Dimensionality reduction  
- Wavelet Decomposition  
- Principal Component Analysis  
  - 많은 데이터들의 projection을 구하여 해당 데이터들을 표현하는 것  
  - 기존 차원에서 더 작은 차원으로 줄인다.  
  - numeric 데이터에 대해서만 작동한다.  
  - steps  
    - 데이터를 normalize 한다.  
    - k-orthonormal 벡터들을 구한다. -> 이를 principle components라고 한다.    
    - 구한 principal components들을 중요성이 높은 순서대로 정렬한다.  
    - 적은 중요도를 갖는 components들은 제거한다.  
    
- Attribute Subset selection  
  - redundant attributes  
    - 제품의 가격과 세금은 서로 계산하여 구할수있으니 중복!!  
  - irrelevant attributes  
    - 학생의 gpa를 구하는 데에는 id는 중요하지 않다!  
   

### 2. Numerosity Reduction  
- 두가지 방식  
  - Parametric methods  
    - regression과 같이 특정 모델로 데이터를 표현하는 것  
    - model parameter를 구해야 한다.  
    - 파라미터만 저장하고 데이터는 버린다.  

  - Non-parametric methods  
    - 히스토그램, 클러스터링, 샘플링 등으로 데이터를 나타내는 방식  
    - 어떤 모델에 기반하여 나타내는 것이 아니다.  
  
- Regression Analysis  
  - 독립변수와 종속변수로 모델링하는 것  
  - 데이터에 가장 잘 맞는 파라미터 값을 추정한다.  
  - prediction에 사용된다. (어떤 값을 예측할때)  
  - linear regression, multiple regression 으로 나눌 수 있다.  
    - linear regression은 independent variable이 한개  
    - multiple regression은 independent variable이 여러개!  
    

- Sampling의 다양한 유형  
  - simple random sampling  
  - sampling without replacement  
    샘플링 했던거 중복없이   
  
  - sampling with replacement  
    샘플링 했던거 중복 허용  
  - stratified sampling  
  
### 3. Data Compression  
- String compression  
- Audio/video compression  
- Time sequence  

## Data transformation  
### Normalization  
노말리제이션에는 다양한 유형이 있다.  
- min-max normalization  
- z-score normalization  
- normalization by decimal scaling  

### Descretization  
- simple discretization: Binning  
  - equal-width partitioning  
    - 동일한 간격으로 분할하여 나눈다.  
  - equal-depth partitioning  
    - 거의 비슷한 샘플들이 한 인터벌에 포함되도록 나눈다.  
