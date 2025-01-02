Thiết kế cấu trúc dữ liệu:

Graph:
    - Vertex: là 1 list có các Node là toàn bộ các Node trong Graph  
        First: node đầu (tự định nghĩa, ko phải là của Graph)
        Last: node cuối (tự định nghĩa, ko phải là của Graph)
            Node: 
                name: là tên của Node
                next: link Node tiếp theo (để mang tính liệt kê chứ không phải là giống như Linked list) 
    - Edge: là 1 list có các node là toàn bộ các Connection của các Node trong graph
        First: connection đầu (tự định nghĩa, ko phải là của Graph)
        Last: connection cuối (tự định nghĩa, ko phải là của Graph)
            Connection: gồm 2 node là node đầu và node cuối của 1 connection
                node_1
                node_2
                next: nối tiếp theo (để mang tính liệt kê)
