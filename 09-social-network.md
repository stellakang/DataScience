# Social network  
- 그래프로 나타낼 수 있으며, node는 사람을(member) edge는 사람간의 관계(relationship)를 나타낸다.  
- examples: friendship networks, media sharing  

## Network를 표현하는 방식  
- simple network/graph  
  - 자기 자신을 가리키는 self-edge나, 두 node사이에 여러 edge가 있는 multi edge가 없는 경우  
- adjacency matrix  
  - 인접행렬로 나타내는 것  
  - 행렬 값은 두 노드 사이에 연결되었을 경우 1, 아니면 0  
- weighted networks  
  - edge가 가중치를 갖는 경우  
- directed network  
  - edge가 방향성을 갖는 경우  
  
  ## Cocitation and Bibliographic Coupling  
  - Cocitation  
    - i,j의 cocitation: i와 j를 모두 가리키는 노드 갯수  
  - Bibliographic Coupling   
    - i,j의 bibliographic coupling은 i와 j가 모두 가리키고 있는 노드 갯수  
    

## Models of Social Network Generation  
- Random graphs  
  - G(N,p)라고 표시하며 N개의 노드는 각각 p의 확률로 다른 노드와 연결된다는 것을 의미.  
  - poisson distribution을 따른다.  
  - 거의 고르게 분포  
  
- Scale-free networks  
  - 네트워크의 노드는 고정된 것이 아니라 계속 확장한다.  
    - ex. www, citation  
  - 많은 링크를 가지고 있는 노드에 연결될 확률이 높다.  
  - 잘 알려진 사이트, 잘 알려진 논문이 더 연결, 인용되기 쉽다.  
  - power law distribution을 따른다.  

## PageRank algorithm  
- 가장 많이 인용된 페이지는 일반적으로 더 중요하다는 가정  
- citation counting으로 단순한 counting을 개선한 것  
- random surfing이라고도 한다.  
- Simple version  
  - 모든 페이지에 동일한 score를 매긴다.  
  - 각 페이지마다 outlink가 있는 노드 갯수만큼 점수를 분산하여 transfer한다.  
  - inlink로 들어온 점수를 더한다. 
  - 문제점  
    - 수렴하지 않는다.  
    - dangling node: page rank score를 얻지만 다른 노드로 전파 불가    
    - cyclic citation: 무한으로 score를 갖게 된다.  
  
- Simple version을 개선한 "Random Surfer Model"  
  - hyperlink를 랜덤으로 클릭하거나! 랜덤으로 다른 페이지로 가거나!  
  - 각 페이지는 a만큼 새로운 임의의 페이지로 jumping(restart) 할수도 있고  
    (1-a)만큼 따라갈 link를 정한다.(random walk)  
  


