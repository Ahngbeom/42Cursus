# netwhat [![bahn's 42 netwhat Score](https://badge42.vercel.app/api/v2/cl1n6fb2j003009l0lfanbfyx/project/2065204)](https://github.com/JaeSeoKim/badge42)

# netwhat 시험.... 주어진 시간은 10분 !

    http://jodies.de/ipcalc - IP 주소 계산기
    https://yeosong1.github.io/netwhat - netwhat 요약 정리
    https://velog.io/@hidaehyunlee/Netwhat-%EC%97%B0%EC%8A%B5%EB%AC%B8%EC%A0%9C-%EC%A0%95%EB%A6%AC - 기출 문제

# 호스트 주소 범위 구하기
    
    문제로 IP 주소와 서브넷 마스크가 주어지고,

    두 요소를 통해 호스트 범위를 알아내기 위해서는

    네트워크 주소를 먼저 구해야한다.

    네크워크 주소는 IP 주소와 서브넷 마스크를 AND 연산을 한 결과이다.

    네트워크 주소의 다음 주소가 호스트 범위 주소의 시작이다.

    또, 브로드캐스트 주소를 구해야 호스트 범위의 끝을 구할 수 있다.

    브로드 캐스트 주소는 네트워크 주소에 와일드 카드 마스크를 OR 연산을 하면 된다.

    와일드 카드 마스크는 서브넷 마스크의 NOT 연산을 한 결과이다.

    브로드 캐스트 주소의 이전 주소가 호스트 범위의 끝이다.

    ex) 158.167.18.156/15
        
        서브넷 마스크가 15. 즉, 255.254.0.0 이다.
        
        158.167.18.156 이 주소의 네트워크 주소는 
        
        158.167.18.156 &(AND 연산) 255.254.0.0 = 158.166.0.0/15 이 된다.

        호스트 주소 범위와 브로드캐스트 주소를 알기 위해서는 와일드 카드라는 것을 알게되면 쉽게 알아낼 수 있다.

        와일드 카드 마스크는 서브넷 마스크의 NOT 연산. 즉 이진수의 값을 반전시킨 결과이다.

        15bit 서브넷 마스크의 와일드 카드 마스크는 0.1.255.255 가 된다.

        네트워크 주소에 와일드 카드 마스크의 주소를 더하면 호스트 주소 범위와 브로드 캐스트 주소를 구할 수 있다.

        네트워크 주소를 뺀 호스트 주소 범위의 시작은 158.166.0.1/15 이 되고,

        브로드 캐스트 주소를 뺀 호스트 주소 범위의 끝은 158.167.255.254/15 가 된다.

# 호스트 주소 수 구하기

    IP Address 는 전체 32bit로 이루어져 있다.

    만약 서브넷 마스크가 /15 라면

    호스트 주소 수는 2^(32 - 15) 개.

    또 서브넷 마스크가 /30 이라면

    호스트 주소 수는 2^(32 - 30) 개.

    즉, 2의 비트수 제곱이다.
    
    1 bit 라면 0 이거나 1. 즉, 경우의 수는 2(2^1)가지이다. 

    2 bit 라면 00, 01, 10, 11. 즉, 경우의 수는 4(2^2)가지이다.

![화면 캡처 2021-01-11 141312](https://user-images.githubusercontent.com/57256332/104148859-53b0aa80-5417-11eb-8ff1-c1c33dfc28b6.png)
![화면 캡처 2021-01-11 141456](https://user-images.githubusercontent.com/57256332/104148879-6aef9800-5417-11eb-8bbe-4aa9b8dca63b.png)
![화면 캡처 2021-01-11 141529](https://user-images.githubusercontent.com/57256332/104148890-79d64a80-5417-11eb-8217-43e85da0d552.png)

# 통신 가능 호스트 주소

    If the IP address 123.48.189.194/21 is assigned to an Ethernet port of a router, what host address could communicate with it?

    IP 주소 123.48.189.194/21이 라우터의 이더넷 포트에 할당 된 경우 어떤 호스트 주소가 라우터와 통신 할 수 있습니까?

    라우터의 이더넷 포트는 LAN(Local Area Network) 장비들과 연결되는 인터페이스로서, 
    LAN 구간에 대한 기본적인 게이트웨이를 수행한다.

    * 게이트웨이는 컴퓨터 네트워크에서 서로 다른 통신망, 프로토콜을 사용하는 네트워크 간의 통신을 가능하게 하는 컴퓨터나 소프트웨어를 두루 일컫는 용어.
    즉, 다른 네트워크로 들어가는 입구 역할을 하는 네트워크 포인트이다.
    넓은 의미로는 종류가 다른 네트워크 간의 통로의 역할을 하는 장치이다. 
    게이트웨이는 서로 다른 네트워크 상의 통신 프로토콜을 적절히 변환해주는 역할을 한다.

    Address:   123.48.189.194        01111011.00110000.10111 101.11000010
    Netmask:   255.255.248.0 = 21    11111111.11111111.11111 000.00000000
    Wildcard:  0.0.7.255             00000000.00000000.00000 111.11111111

    Network:   123.48.184.0/21       01111011.00110000.10111 000.00000000 (Class A)
    Broadcast: 123.48.191.255        01111011.00110000.10111 111.11111111
    HostMin:   123.48.184.1          01111011.00110000.10111 000.00000001
    HostMax:   123.48.191.254        01111011.00110000.10111 111.11111110
    Hosts/Net: 2046                  

    * Routing : 어떤 네트워크 안에서 통신 데이터를 보낼 때 최적의 경로를 선택하는 과정이다. 최적의 경로는 주어진 데이터를 가장 짧은 거리로 또는 가장 적은 시간 안에 전송할 수 있는 경로다.

# 사설 IP

    Class A : 10.0.0.0 ~ 10.255.255.255
    Class B : 172.16.0.0 ~ 172.31.255.255
    Class C : 192.168.0.0 ~ 192.168.255.255

# TCP vs UDP
  
    TCP와 UDP는 TCP/IP의 전송계층에서 사용되는 프로토콜이다. 전송계층은 IP에 의해 전달되는 패킷의 오류를 검사하고 재전송 요구 등의 제어를 담당하는 계층이다.

    TCP는 Transmission Control Protocol의 약자이고, UDP는 User Datagram Protocol의 약자이다. 두 프로토콜은 모두 패킷을 한 컴퓨터에서 다른 컴퓨터로 전달해주는 IP 프로토콜을 기반으로 구현되어 있지만, 서로 다른 특징을 가지고 있다.

    TCP는 송신자가 데이터를 전달하려할때 수신자에게 보내기 전에 받을 준비가 되어있는지 확인을하고, 데이터를 보내겠다는 메시지와 함께 잘 도착했는지까지 확인을 한다.

    Data Sequencing : TCP에서는 데이터의 순서번호를 표기하여 데이터의 신뢰성을 보장한다.

![image](https://user-images.githubusercontent.com/57256332/103745546-04e3c900-5043-11eb-8ec6-f0a04d18fd1f.png)

    반면, UDP는 일방적으로 데이터를 수신자에게 보내기만 한다.

    ![image](https://user-images.githubusercontent.com/57256332/103745623-22b12e00-5043-11eb-80fe-c8fcb5ab092e.png)

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F2254775057586D6F10F5E5">
    

    UDP 서비스를 사용하는 프로토콜 : SNMP(Simple Network Management Protocol), DHCP(Dynamic Host Configuration Protocol)

# Which IP address class has more host addresses available by default?
    
기본적으로 더 많은 호스트 주소를 사용할 수있는 IP 주소 클래스는 무엇입니까?

    A. FIRST

FIRST CLASS is A CLASS 

A 클래스는 아래 그림과 같이 host의 주소 범위가 다른 클래스들보다 가장 크다.

<img src="https://t1.daumcdn.net/cfile/tistory/99068D495BE8101D34">

# Which protocol does Ping use?

Ping은 어떤 프로토콜을 사용합니까?

    A. ICMP(Internet Control Message Protocol)

* ICMP의 용도? 

    - 인터넷/통신 상에서 발생한 일반적인 상황에 대한 보고(report)

    - 인터넷/통신 상에서 발생한 오류에 대한 보고

    - 위험한 상황에 대한 경보

* ICMP의 기능?

    - IP 프로토콜을 이용하여 ICMP 메세지 전달 

    - 네트워크 계층에 속하여 네트워크 관리 프로토콜의 역할 수행 

    (여기서 포인트는 종단간 데이터 수송 역할 X)

ICMP 프로토콜은 Network 계층에 속하며 IP 프로토콜과 같이 사용한다! 

* ICMP 사용(활용) 명령어 

1. Ping 명령어 : 상대방 호스트의 작동 여부 및 응답시간 측정하는데 사용

    - Echo Request (ICMP 질의메세지 요청)

    - Echo Reply (ICMP 응답메세지 요청)

2. Tracert명령어 : 목적지까지의 라우팅 경로 추적을 하기 위해 사용 

    - Time Exceeded 확인 가능

# DHCP (Dynamic Host Configuration Protocol)

    DHCP implement a mechanism that automates IP configuration, including IP address, subnet mask, default gateway and DNS information

    번역) DHCP는 IP 주소, 서브넷 마스크, 기본 게이트웨이 및 DNS 정보를 포함한 IP 구성을 자동화하는 메커니즘을 구현합니다.

<a href="https://jwprogramming.tistory.com/35"> 참고자료 </a>

    DHCP란 호스트의 IP주소와 각종 TCP/IP 프로토콜의 기본 설정을 클라이언트에게 자동적으로 제공해주는 프로토콜을 말합니다. 
    
    DHCP에 대한 표준은 RFC문서에 정의되어 있으며, DHCP는 네트워크에 사용되는 IP주소를 DHCP서버가 중앙집중식으로 관리하는 클라이언트/서버 모델을 사용하게 됩니다.
    
    DHCP지원 클라이언트는 네트워크 부팅과정에서 DHCP서버에 IP주소를 요청하고 이를 얻을 수 있습니다.

    네트워크 안에 컴퓨터에 자동으로 네임 서버 주소, IP주소, 게이트웨이 주소를 할당해주는 것을 의미하고, 해당 클라이언트에게 일정 기간 임대를 하는 동적 주소 할당 프로토콜입니다.

# What are the different layers of the OSI model?

    A. Application - Presentation - Session - Transport - Network - Data Link - Physical

    
67414141414142662d4947574c306f6877673650662d32514146466b572d566343766c324b7937597175694f426b706a39724b55654c7174723139486c64786c6f476c4d736a514164715932764158544f356d72587348686a42616f4a7a6334544a4343453868684a39646a79484e7a48654152354a6a4e4d6461535839487569693453564f5a69646c536246464a305362445f3456657970636c375a6743786d466970495552374936414e334f6d5749347572396b6f61516639786f4546496a38515432425f506b6658434363426e5876375957686f677a4561373359697972515f4846334b4b727068677838475768693259664e7a4c516c7050474f425f376a474447795a57303734316850715559614b6d454e3347326335676f694b4c715f6a7032452d38397578457279316855576c6876354864397343526d5576705550694f79706f7856556853466d7479536459676331494645464b71446f563050773642764e30337a395047717a33744a6f79374539326270577852784e475244566f5a4b696a2d7941624a55586f576e3737736c7049614b6e6a73594b7745525a4d36696337386d465f386f3775527361716f7431736a795532716b49764a36776d69616f38747659466c6b795a633243483661314c2d45736c53786f5a6259513d3d

<hr>

# netwhat 시험 문제 해설

1. Which of the following is the valid host range for the subnet on which the IP address 81.180.198.194/29 resides?
   
   => 해당 IP 주소가 속한 서브 네트워크의 유효한 호스트 범위를 구하는 문제이다.
        
        * 서브넷(subnet)은 "subnetwork을 줄인 말로서 어떤 기관에 소속된 네트웍이지만 따로 분리되어 있는 한 부분으로 인식될 수 있는 네트웍을 말한다. 일반적으로 하나의 서브넷은 하나의 지역, 한 빌딩 또는 같은 근거리통신망 내에 있는 모든 컴퓨터들을 나타낼 수 있다. 여러 개의 서브넷으로 나뉘어진 어떤 조직의 네트웍은 인터넷에 하나의 공유된 네트웍 주소로 접속될 수 있다. 만약 서브넷이 없다면, 그 조직은 물리적으로 분리된 서브 네트웍마다 하나씩, 여러 군데의 인터넷 접속을 가지게 될 것이며, 그렇게 함으로써 한정된 량의 인터넷 주소가 쓸모 없이 낭비될 수도 있게된다.

        서브넷은 말그대로 부분망이라는 뜻입니다. IP 주소에서 네트워크 영역을 부분적으로 나눈 부분망, 부분 네트워크를 뜻하죠. 그리고 이 서브넷을 만들 때 쓰이는 것이 바로 서브넷 마스크입니다. 이 서브넷 마스크를 이용하여 IP주소 체계의  Network ID와 Host ID를 서브넷 마스크를 통해 분리할 수 있습니다.

        81.180.198.194의 네트워크 주소는

        IP주소:         81.180.198.194        01010001.10110100.11000110.11000 010
        넷마스크:       255.255.255.248 = 29  11111111.11111111.11111111.11111 000
                                                AND 연산
        네트워크주소:   81.180.198.192/29   = 01010001.10110100.11000110.11000 000

        81.180.198.194의 브로드캐스트 주소는 와일드카드 마스크를 이용하여 구한다.

        와일드 카드 마스크는 넷마스크의 NOT 연산을 한 결과이다.

        넷마스크:   255.255.255.248 = 29  11111111.11111111.11111111.11111 000
                                            NOT 연산
        와일드카드: 0.0.0.7             = 00000000.00000000.00000000.00000 111

        브로드캐스트 주소는 네트워크 주소에 와일드카드 마스크를 OR 연산을 한 결과이다.

        네트워크주소:   81.180.198.192/29     01010001.10110100.11000110.11000 000
                                                OR 연산
        와일드카드:     0.0.0.7               00000000.00000000.00000000.00000 111
        Broadcast:      81.180.198.199      = 01010001.10110100.11000110.11000 111

        네트워크 주소와 브로드캐스트 주소를 제외한 범위가

        81.180.198.194/29 가 속한 서브 네트워크의 유효한 호스트 범위이다.

        A. 81.180.198.193 - 81.180.198.198

2. What is the default subnet mask for a class C network?

    => IP 클래스 중 C 클래스의 기본 서브넷 마스크를 묻는 문제이다.

    <img src="https://t1.daumcdn.net/cfile/tistory/99068D495BE8101D34">

        클래스마다 기본 서브넷 마스크는 네트워크 주소 부분을 1로 치환한 결과이다.

        그림에서 C 클래스 부분을 보면 
        
        24bit 까지 네트워크 주소로 사용하기 때문에 

        기본 서브넷 마스크는 255.255.255.0 이다. 

        서브넷 마스크를 통해 IP 주소와 계산하게 되면

        유효한 호스트 주소의 범위를 구할 수 있게 된다.

        A. 255.255.255.0

3. Which of the following is private IP address?
   
   => 사설 IP 주소(Private IP Address)를 고르는 문제이다.

        사설 IP 주소는 

        Class A : 10.0.0.0 ~ 10.255.255.255
        Class B : 172.16.0.0 ~ 172.31.255.255
        Class C : 192.168.0.0 ~ 192.168.255.255

        이므로,

        4개의 보기 중 사설 IP 주소에 해당하는 주소는 

        10.236.145.109 이다.

        A. 10.236.145.109

4. If an Ethernet port on a router were assigned an IP address of 149.8.199.5/18, which host address would be able to communicate with it?

    => 라우터의 이더넷 포트에 할당된 IP 주소가 통신할 수 있는 다른 호스트 주소를 고르는 문제이다.

        149.8.199.5/18 가 속한 서브네트워크 범위안에 있는 호스트 주소를 고르면 된다.

        1번 문제와 동일하게 네트워크 주소와 브로드캐스트 주소를 구한 후

        네트워크 주소와 브로드캐스트 주소를 제외한 범위 안에 해당하는 호스트 주소를 보기에서 고르면 된다.

        A. 149.8.230.81

5. Which class of IP address has the most host addresses available by default?

    => IP 클래스 중 기본적으로 가장 많은 호스트 주소를 가질 수 있는 클래스를 묻는 문제이다.

    <img src="https://t1.daumcdn.net/cfile/tistory/99068D495BE8101D34">
        
        그림을 보면 호스트 주소 범위가 가장 큰 클래스는 A 클래스이다.

        A. A

6. 1번 문제와 동일

7. What is the maximum number of IP addresses that can be assigned to hosts on a local subnet that uses the 255.192.0.0 subnet mask?

    => 해당 서브넷 마스크가 가질 수 있는 호스트 주소 수를 구하는 문제이다.

        먼저 서브넷 마스크가 가질 수 있는 주소 수는 
        
        2의 (IP 주소의 전체 bit 수 - 서브넷 마스크 bit 수) 제곱을 한 결과이다.

        따라서, 255.192.0.0 는 11111111.11000000.00000000.00000000

        bit 수는 10 이다.

        주소 수를 계산해보면 2 ^ (32 - 10) = 2 ^ 22 = 4194304 이다.

        지금 계산한 주소 수는 네트워크 주소와 브로드캐스트 주소까지 포함한 주소 수이기 때문에 호스트가 가질 수 있는 주소 수는 전체 주소 수에서 2를 빼준 값이 된다.

        즉, 4194304 - 2 = 4194302

![화면 캡처 2021-01-11 141312](https://user-images.githubusercontent.com/57256332/104148859-53b0aa80-5417-11eb-8ff1-c1c33dfc28b6.png)
![화면 캡처 2021-01-11 141456](https://user-images.githubusercontent.com/57256332/104148879-6aef9800-5417-11eb-8bbe-4aa9b8dca63b.png)
![화면 캡처 2021-01-11 141529](https://user-images.githubusercontent.com/57256332/104148890-79d64a80-5417-11eb-8217-43e85da0d552.png)

        A. 4194302

8. 4번 문제와 동일

9. Which of this is not true?

    TCP is reliable as it guarantees delivery of data to the destination router
        O - TCP는 대상 라우터로의 데이터 전달을 보장하기 때문에 신뢰할 수 있다.

    TCP supports Broadcasting
        X - 브로드캐스팅을 지원하는 프로토콜은 UDP 이다.
            <a href="https://m.blog.naver.com/PostView.nhn?blogId=kbm0996&logNo=221045822230&proxyReferer=https:%2F%2Fwww.google.com%2F">참고블로그</a>

    Sequencing of data is a feature of TCP (this means that packets arrive in-order at the receiver)
        O - TCP는 데이터에 순서번호를 매겨서 전달한다. 수신자에게 각 데이터의 순서번호를 통해 정상적으로 전달되었는지 확인하기 위함이다.
    
    TCP is a connection-oriented protocol
        O - TCP는 연결 지향형 프로토콜이다.
    
    TCP is comparatively slower than UDP
        O - TCP는 UDP 보다 비교적 느리다.

    TCP provides extensive error checking mechanisms. It is because it provides flow control and acknowledgment of data
        O - TCP는 광범위한 오류 검사 메커니즘을 제공한다. 흐름 제어 및 데이터 승인을 제공하기 때문이다.

10. What is the Network address of a host with an IP address of 128.134.27.135/25?

    => 해당 IP 주소의 네트워크 주소를 구하는 문제이다.

        해당 IP 주소와 서브넷 마스크를 AND 연산을 하면 네트워크 주소를 구할 수 있다.

        Address:   128.134.27.135        10000000.10000110.00011011.1 0000111
        Netmask:   255.255.255.128 = 25  11111111.11111111.11111111.1 0000000
                                            AND 연산
        network:   128.134.27.128/25   = 10000000.10000110.00011011.1 0000000

        A. 128.134.27.128

11. 결론적으로 호스트 주소 수를 구하는 문제이기 때문에 7번 문제와 동일

12. 4, 8번 문제와 동일

13. 3번 문제와 동일

14. 10번 문제와 동일 
    
15. Which of this is not true?

    Sequencing of data is a feature of UDP (this means that packets arrive in-order at the receiver)
        X - 데이터 시퀀싱은 TCP의 기능이다. 

    UDP supports Broadcasting
        O - UDP는 브로드캐스팅을 지원한다.
    
    UDP is faster, simpler and more efficient than TCP
        O - UDP는 TCP보다 빠르고 간단하며 효율적이다.
    
    The delivery of data to the destination cannot be guaranteed in UDP
        O - 대상으로의 데이터 전달은 UDP에서 보장 할 수 없습니다.
            TCP 에서 데이터 전달을 보장한다.
            
    UDP is a datagram-oriented protocol
        O - UDP는 비연결형 서비스를 지원하는 전송계층 프로토콜
            사용자 데이터그램형 프로토콜이다.

    UDP has only the basic error checking mechanism using checksums
        O - UDP는 체크섬을 사용하는 기본 오류 검사 메커니즘만 있다.

16. 10, 14번 문제와 동일

17. Which protocol does DHCP use at the Transport layer?

    => DHCP는 전송 계층에서 어떤 프로토콜을 사용하는지 묻는 문제이다.

    <a href="https://ddooooki.tistory.com/57">DHCP 참고 블로그</a>

       UDP 서비스를 사용하는 프로토콜 : SNMP(Simple Network Management Protocol), DHCP(Dynamic Host Configuration Protocol)

       DHCP 클라이언트는 브로드캐스팅을 통해 DHCP 서버에게 IP 주소를 요청한다.
       
       A. UDP

18. 1, 6번 문제와 동일

19. 7, 11번 문제와 동일

20. To test the IP stack on your local host, which IP address would you ping?
    
    => 결론적으로 로컬호스트의 주소를 묻는 문제이다.

        로컬호스트란 컴퓨터 네트워크에서 사용하는 루프백 호스트명으로,
        자신의 컴퓨터를 의미한다.

        루프백은 자기 자신에게 IPv4 패킷을 전송함으로써

        인터넷 WEB 상에서의 자기 자신의 컴퓨터 위치를 식별 및 구별할 수 있는 위치라는 뜻과 동일한 특수 목적의 IP 주소이다. 

        로컬 컴퓨터를 원격 컴퓨터인것 처럼 통신할 수 있어 테스트 목적으로 주로 사용된다.

        네트워크에선 특수한 IP 주소로 127.0.0.1이라는 IP 주소가 있다. 한 번씩 봤을 법한 주소인데, 이는 루프백(loopback) 혹은 로컬호스트 주소(localhost)라고도 불린다. 

        데이터 패킷을 전달할 때 목적지 IP 주소를 127.0.0.1로 설정하게 되면 
        데이터 패킷을 외부로 전송하지 않는다. 
        전송하지 않고 고스란히 자신이 다시 받은 것처럼 처리한다 
        즉, 자신이 송신한 패킷을 그대로 수신한 효과를 준다. 

        A. 127.0.0.1
