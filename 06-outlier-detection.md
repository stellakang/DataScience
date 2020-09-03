# Outlier Detection  

## 1. Concepts  

- 정의: 다른 오브젝트들과 상대적으로 유사하지 않은 오브젝트를 outlier이라고 한다.  
- 응용 분야: 네트워크 침입 탐지 시스템, 약물 오용, 금융 사기 탐지  
- Previous methods: Statistics-based outlier detection, Distance-based outlier detection,  
                    Density-based outlier detection, RWR-based outlier detection  
                    
## 2. Statistics-based Outlier Detection  
- 통계 기반 방식!  
- 가장 적당한 통계 분포 모델을 찾는다. (statistical distribution model)  
- 분포에서 벗어난 오브젝트를 outlier로 찾는다.  
- 문제점: 대부분 실제 데이터는 특정 분포로부터 생성되지 않는다./ multi dimension의 경우 특정 분포를 찾기 어렵다.  


## 3. Distance-based Outlier Detection  
- 오브젝트 사이 거리를 특성으로 사용한다.  
- d거리 이내에 존재하는 object의 수가 p개보다 적으면 outlier로 본다.  
- 문제점: local density problem을 겪는다.  

## 4. Density-based Outlier Detection. 
- 주변 object와 비교해서 밀도가 낮으면 outlier로 판단!  
- 문제점: 주변 object와 밀도가 비슷하지만 주변 object를 포함하여 모두 outlier인 경우  
  outlier로 판단하지 못한다.  
  
## New approach  
### Our goals  
- 아웃라이어를 정확히 판단한다.  
- 아웃라이어 정도를 점수화한다.  
- 데이터 형태나 타입과 관계없이 다룰 수 있다.  
- 파라미터 수는 최대한 적어야하며 파라미터 값에 영향을 적게 받아야 한다.  

### Our Procedures    
- 주어진 데이터를 k-NN graph로 모델링한다.     
- centrality, center-proximity 점수를 계산한다.  
  - 이를 바탕으로 outlier 점수 계산  
- top m object를 outlier로 판단한다.  

### Centrality and Center-Proximity  
- Centrality   
  - object p의 centrality score는 얼마나 다른 object가 p를 해당 클러스터의 center로 인식하는지!!  
  - 어떤 경우에 증가하는가  
    - p를 neighbor로 인식하는 object수가 많을수록  
    - p를 neighbor로 인식하는 object의 center-proximity 점수가 높을수록  
    - p를 neighbor로 인식하는 object들이 p와 가까울수록  

- Center-Proximity  
  - object p의 center-proximity score는 얼마나 p가 속한 클러스터의 센터와 가까운지  
  - 어떤 경우에 증가하는가  
    - p가 neighbor로 인식하는 object수가 많을수록  
    - p가 neighbor로 인식하는 object들의 centralith 점수가 높을수록  
    - p가 neighbor로 인식하는 object들이 p와 가까울수록  
    
- 계산법 알기!!  

## Graph Modeling Schemes  
### Complete graph  
- 각 노드마다 n-1개의 edge를 이어준다.  
- centrality, center-proximity score는 모든!! 다른 오브젝트에 영향을 받는다.  

### e-NN graph  
- 특정 거리 e안에 존재하는 object들과 연결한다.  
- e 값에 따라 많은 영향을 받는다.  

### k-NN graph  
- k개의 가까운 obejct들을 연결한다.  
- 모든 object들의 out degree는 동일  
- indegree는 object들의 분포에 따라 다름  
- k값에 따라 변화  
  - k가 작으면 모든 object들이 드물게 연결  
  - k가 크면 클러스터가 적당히 형성  
  - k가 너무 크면 complete graph와 비슷  
- 다른 그래프에 비해 k-NN이 k값에 따라 크게 변동하지 않는다.  

## Weight assignment  
- Euclidean similarity  
- Cosine similarity  





