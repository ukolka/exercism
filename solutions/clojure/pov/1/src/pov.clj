(ns pov)


(defn node-list
  ([graph] 
   (let [root (first graph)
         sub-graphs (rest graph)]
     (if (empty? sub-graphs)
       [root]
       (cons root
             (apply concat
                    (map #(node-list %) sub-graphs))))))) 

(defn path-from-root-to 
  ([node graph]
   (path-from-root-to node graph []))

  ([node graph visited]
   (if (= node (first graph))
     (conj visited node)
     (first (filter seq
                   (map 
                    #(path-from-root-to 
                      node 
                      %1 
                      (conj visited (first graph))) 
                    (rest graph)))))
   ))

(defn path-from-to-through-root [node1 node2 graph]
  (let [root-to-node1 (path-from-root-to node1 graph)
        root-to-node2 (path-from-root-to node2 graph)]
    (when (not (or (nil? root-to-node1) (nil? root-to-node2)))
      (loop [path (seq root-to-node1)
             result root-to-node2]
        (if (seq path)
          (recur (rest path) 
                 (if (= (first path) (first result))
                   result
                   (cons (first path) result)))
          result)))))

(defn path-from-to [node1 node2 graph]
  (let [path (path-from-to-through-root node1 node2 graph)
        root (first graph)]
    (when (and (not= node1 node2) (not (nil? path)))
      (loop [from-node1 (reverse (take-while #(not (= root %)) path))
             from-node2 (reverse (take-while #(not (= root %)) (reverse path)))
             last-common-ancestor root]
        (let [ffrom-node1 (first from-node1)
              ffrom-node2 (first from-node2)]
          (if (= ffrom-node1 ffrom-node2)
            (recur 
             (rest from-node1) 
             (rest from-node2)
             ffrom-node1)
            (concat (reverse from-node1) [last-common-ancestor] from-node2)))))))

(defn single-path-graph
  ([route] (single-path-graph route []))
  ([route graph]
   (if (empty? route)
     graph
     (let [sub-graph (single-path-graph (rest route) graph)]
       (if (not (empty? sub-graph)) 
         [(first route) sub-graph]
         [(first route)])))))


(defn add-path-to-graph 
  ([path graph] (add-path-to-graph path graph []))
  ([path graph result]
   (let [current-path (first path)
         next-path (first (rest path))
         graph-root (first graph)
         sub-graphs (rest graph)
         next-sub-graph (first (filter #(= (first %) next-path) sub-graphs))
         other-sub-graphs (filter #(not= (first %) next-path) sub-graphs)]
     (if (not (empty? (rest path)))
       (if (empty? next-sub-graph)
         (let [parent (first graph)
               new-child (single-path-graph (rest path))
               children (rest graph)]
           (conj
            (into [parent] children)
            new-child)
           )
         (let [new-sub-graph (add-path-to-graph (rest path) next-sub-graph)]
           (conj 
            (into [graph-root] other-sub-graphs) 
            new-sub-graph)
           ))
       graph))))

(defn of [node graph]
  (let [all-end-nodes (node-list graph)
        end-nodes (filter #(not= node %) all-end-nodes)
        paths (mapv #(path-from-to node % graph) end-nodes)
        result (single-path-graph (first paths))]
    (cond 
      (not (empty? end-nodes))
      (let [out-graph (reduce #(add-path-to-graph %2 %1) result (rest paths))]
        (when (not (empty? out-graph))
          out-graph))

      (not (empty? all-end-nodes))
      graph

      :default nil)))
