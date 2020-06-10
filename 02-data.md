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
  sample의 mean: (샘플의 x의 합)/(x의 갯수)  
  전체의 mean: (전체 x의 합)/(전체 x의 갯수)  
  - weighted arithmetic mean(샘플마다 중요도 반영)  
  - trimmed mean(너무 극단적인 값이 있다면 제외하고 계산)  
  
- Median  
  mean은 아웃라이어에 영향을 많이 받는다는 단점!  
  
  - 홀수개의 데이터인 경우 가장 가운데 값, 짝수개의 데이터인 경우 가운데 두개값의 평균  
  - 새로운 값이 들어오면 처음부터 구해야하기 때문에 interpolation으로 추정하는 방법 사용.  
    처음에 구간을 나누고 도중에 새로운 데이터가 들어오면 그 데이터가 해당하는 구간의 frequency를 한 개 올려준다.  
    median = L1(구간의 시작지점) + ((n/2-sum(이전 freq))/(median frequency))x width  
    
    ex. 
    |age|frequency|
    |:-:|:-------:|
    |1-5|200|
    |6-15|450|
    |16-20|300|
    |21-50|1500|
    |51-80|700|
    |81-110|44|
    
    median = 21 + ((1597-950)/(1500))x29 = 21 + 18763/1500  
    
    
- Mode  
  : 최빈값  
  - 가장 데이터에서 많이 등장하는 값  
  - 가장 빈도 높은 것 1,2,3개 선택: unimodal, bimodal, trimodal  
  - empirical formula  
    - 통계적으로 아래 식을 만족함  
      mean-mode=3x(mean-median)  
      평균에서 최빈값 뺀 것은 평균에서 중앙값 뺀 것의 3배이다.  
      
    - symmetric vs skewed data  
      위의 식에서 2개를 알고있으면 나머지 하나를 예측할 수 있다.  
      symmetric -> mean=median=mode  
      skewed -> mean>median>mode인 경우, positively skewed  
             -> mode>median>mean인 경우, negatively skewed  
         
    

### 2. Measuring the Dispersion of Data  

1) Measurements    
- quartiles  
  Q1(25th percentile), Q3(75th percentile)를 의미  
  Q2(50th percentile)==median  
  Q4(100th percentile)==meaningless  
  
- Inter-quartile range(IQR)  
  IQR = Q3-Q1  
  
- Five number summary  
  min, Q1, median, Q3, max  
  
- Boxplot  
  : graphical tool  
  뒤에서 자세히 나옴  
  
- Outlier  
  값이 1.5xIQR보다 작거나 큰 값  

- Variance  
  분산 -> 편차 제곱의 평균    
  sample의 variance: sum((xi-x의평균)^2)/(n-1)  *n-1로 나눈다*  
  전체 데이터의 variance: sum(xi^2)/N - 평균^2 *n으로 나누며 간단하게 (**제**곱의 **평**균)-(**평**균의 **제**곱)으로*    
  
- Standard deviation  
  s또는 시그마는 variance의 루트  

2) Boxplot Analysis  
- Five-number summary  
  minimum, Q1, median, Q3, Maximum  
  
- Boxplot  
  - box로 표현한다.  
  - box의 왼쪽 끝은 Q1, 오른쪽 끝은 Q3  
  - median은 box안에 선으로 표기한다.  
  - box 바깥은 선으로 연결하여 minimum, maximum까지 연결한다.  
  - outliers: outlier threshold를 넘어간 곳에 점으로 표기한다.  

3) Properties of Normal Distribution Curve  

- 뮤-시그마 to 뮤+시그마: 68%를 포함한다.  
- 뮤-2시그마 to 뮤+2시그마: 95%를 포함한다.  
- 뮤-3시그마 to 뮤+3시그마: 99.7%를 포함한다.  


## Data Visualization  

### 1. Boxplot  
: 5개의 숫자(min, q1, median, q3, max)를 시각적으로 보여줌.  


### 2. Histogram  
: x축은 값, y축은 빈도를 나타내는 막대 형태의 그래프.  

- 막대는 서로 인접해있고 겹치지 않는다.  
- 막대그래프와 차이  
  - 막대그래프는 높이가 그 값을 나타낸다.  
  - 히스토그램은 넓이가 그 값을 나타낸다.  
  - 각 막대가 서로 다른 너비를 가지면 중요한 차이를 보일 것!!  
  
- boxplots보다 더 많은 정보를 전달하기도 한다.  
  - min, q1, median, q3, max값이 모두 같아도 median쪽에 빈도가 더 많아도 되고  
    그 주변에 대칭으로 많아도 되기 때문에 boxplot자체는 완전히 같지만 데이터 분포는 달라진다.  


### 3. Quantile plot  
: x값과 f를 쌍으로 표기하는 방식으로 이때 f는 100fi%는 <=xi이라는 것을 의미한다.  

- 모든 데이터를 표기.  
- f를 0, 0.25, 0.5, 0.75, 1.00에 눈금을 두어 데이터들이 어느 지점에서 0퍼이고 25퍼인지 등을 표기  
- 전체적인 분포도 알 수 있고 부분적으로 가파른 부분이나 완만한 부분 등을 알 수 있다.  

### 4. Quantile-quantile plot  
- 한 분포의 quantiles와 이에 대응하는 다른 분포의 quantiles를 표기한다.  
- 예를 들어, branch1, branch2가 있으면 branch1 축의 40,50,...,120 값의 분포에 대해 branch2는 어떻게 분포하는지 점으로 표기    
  branch2가 더 높은 값일 때, branch1이 더 낮은 값이면 branch2가 더 가격이 높은 것  
  
### 5. Scatter plot  

- 각 값이(예를 들어 아이템 가격과 팔린 갯수) 평면에 점으로 표현된다.  
- 각 점들의 클러스터와 아웃라이어를 찾을 수 있게 한다.  
- positively, negatively correlated data를 알 수 있게 한다.  
  증가할 때 같이 증가하면 positive, 증가할 때 감소하면 negative  


## Measuring Data Similarity and Dissimilarity  

### 1. Similarity and Dissimilarity  

- Similarity  
  - 두 data objects가 얼마나 비슷한지 수치로 나타내는 것  
  - 두 objects가 비슷할수록 더 값이 크다.  
  - 0,1 사이의 값을 가진다.  
  
  
- Dissimilarity(=distance)  
  - 두 data objects가 얼마나 다른지 수치로 나타내는 것  
  - 두 objects가 비슷할수록 더 값이 작다.  
  - 같은 object인 경우 0값을 갖는다.  
  - 상황에 따라 upper limit이 다르게 설정된다.  
  
- Proximity  
  similarity나 dissimilarity를 둘다 나타낸다.  

### 2. Data matrix and Dissimilarity matrix  

- Data matrix  
  - n개의 데이터마다 가지는 p개의 attribute들을 나타낸다.  
  - 한 row가 하나의 데이터를 나타내며 전체 row는 전체 데이터 샘플을 나타낸다.  
  - column별로 애트리뷰트의 값이 저장되어있는 행렬이다.  
  - two modes: 한 차원은 sample, 다른 한 차원은 attribute를 나타낸다.  
  
- Dissimilarity matrix  
  - n개의 데이터가 있으나 여기서는 페어마다 distance를 저장한다.  
  - symmetric하기 때문에 triangular matrix이다.  
  - single mode: 두 차원 모두 object를 나타낸다.  
  

### 3. Proximity Measure  

  - Nominal Attributes   
    둘 중 하나 적용   
    - method1: simple matching  
      m: the number of matches, p: total number of variables  
      d(i,j)=(p-m)/p  
      
    - method2: binary attributes를 많이 사용  
      binary attribute로 각 상태를 나타내서 yellow이면 yellow=1, 나머지 red, green, ..., =0으로 나타낸다.   
  
  - Binary Attributes  
    - contingency table을 사용한다.  
      <table>
        <thead>
            <tr>
                <th></th>
                <th colspan=4 style="text-align:center">Oj</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td rowspan=4>Oj</td>
                <td></td>
                <td style="text-align:center">1</td>
                <td style="text-align:center">0</td>
                <td style="text-align:center">sum</td>
            </tr>
            <tr>
                <td style="text-align:center">1</td>
                <td style="text-align:center">q</td>
                <td style="text-align:center">r</td>
                <td style="text-align:center">q+r</td>
            </tr>
            <tr>
                <td style="text-align:center">0</td>
                <td style="text-align:center">s</td>
                <td style="text-align:center">t</td>
                <td style="text-align:center">s+t</td>
            </tr>
            <tr>
                <td style="text-align:center">sum</td>
                <td style="text-align:center">q+s</td>
                <td style="text-align:center">r+t</td>
                <td style="text-align:center">p</td>
            </tr>
        </tbody>
      </table>
  
    
    
    - Distance measure  
      - symmetric binary variables  
        d(i,j) = (r+s)/(q+r+s+t)  
      - asymmetric binary variables  
        d(i,j) = (r+s)/(q+r+s)  
        
      > 대칭인건 다 더해서 값 서로 다른거 비율 구하고!!  
        비대칭인건 둘다 0인거 제외하고 다른거 비율 구하기!  
        
    - Jaccard coefficient(similarity measure for asymmetric binary variables)  
      sim(i,j) = q/(q+r+s)
         
  
  - Numeric Attributes  
    
    - Minkowski distance(=L-h norm)    
      : distance 구하는 유명한 방식  
      
      
      d(i,j)=rootk(sum((xik-xjk)^k))  
      - h=1: manhattan distance  
      - h=2: euclidean distance  
      - h->무한대: Supremum distance  
        애트리뷰트끼리 차이가 가장 큰 값 = max|xif-xjf|  
        
      
      **Properties**
      - 항상 0보다 크거나 같다.  
      - symmetric  
      - d(i,j)<=d(i,k)+d(k,j)  
      -> 이 특성 만족하는 distance를 **metric**이라고 한다.  
      
    
  - Ordinal Attributes  
      
    interval-scaled로 바꾼다.
    1) 값을 rank로 바꾼다.  
    2) 값을 0-1사이 범위로 바꾼다.  
    -> 실제 값이 rif라면 여기서 1빼고 highest rank에서 1뺀거
    
    Zif = (rif-1) / ( Mf - 1 )  
    - Mf: highest rank값  
    
    3) interval-scaled variables를 계산할 때 사용한 방식으로 dissimilarity를 계산  
    
  
  - Mixed Type  
    - nominal, symmetric binary, asymmetric binary, numeric, ordinal 모두 포함할 것     - weighted formula를 이용한다.
      각 object에 대한 weight와 dij(f)를 곱하는 weighted sum이며 이때 dij(f)는
      - f가 binary, nominal일 때, 
        서로 같으면 dij(f)=0, 서로 다르면 dij(f)=1  
      - f가 숫자면  
        normalized distance를 사용한다.  
      - f가 ordinal이면  
        rank를 계산하고 Zif를 구한다.  
  
  
### 4. Standardizing Numeric Data    
  
  - Z-score
    Z=(x-avg)/std  
    - X: 표준화될 raw score  
    - 뮤: 전체 데이터 평균  
    - std: 표준편차  
    
  - Meaning  
    : raw score - mean
    - "-"이면 평균 아래  
    - "+"이면 평균 위  
    
  - 표준편차 대신 (편차의 절댓값의 합의 평균)을 사용(mean absolute deviation)할 수 있다.  
    -> 아웃라이어는 제곱을 사용하면 값이 더 커지기 떄문에 mean absolute deviation이 더 robust  


### 5. Cosine Similarity  

- 다큐먼트마다 각 단어의 빈도수를 기록한 행렬이 있다고 하자.  
  한 다큐먼트가 다른 다큐먼트의 두배라면 유사도는 비슷해야 하는데 유클리디안으로 계산하면 너무 값이 커진다.  
  -> 이를 해결하기 위해서 cosine similarity 사용  

- cos(d1, d2) = (d1, d2 내적)/(d1크기)x(d2크기)  


