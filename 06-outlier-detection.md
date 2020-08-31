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
- 문제점: local density problem을 겪는다.(

