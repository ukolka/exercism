pub struct SimpleLinkedList<T> {
    head: Option<Box<Node<T>>>,
    length: usize,
}

struct Node<T> {
    data: Option<T>,
    next: Option<Box<Node<T>>>,
}

impl<T> Node<T> {
    fn get_data(&self) -> Option<&T> {
        self.data.as_ref()
    }
}
           
impl<T> SimpleLinkedList<T> {
    pub fn new() -> Self {
        SimpleLinkedList {
            head: None,
            length: 0
        }
    }

    pub fn len(&self) -> usize {
        self.length
    }

    pub fn push(&mut self, element: T) {
        let head = self.head.take();
        let next = Some(Box::new(Node {
            data: Some(element),
            next: head,
        }));
        self.head = next;
        self.length += 1;
    }

    pub fn pop(&mut self) -> Option<T> {
        if self.head.is_none() {
            return None;
        }
        let mut head = self.head.take().unwrap();
        let next = head.next.take();

        self.head = next;
        self.length -= 1;

        head.data
    }

    pub fn peek(&self) -> Option<&T> {
        match self.head {
            Some(ref head) => head.get_data(),
            None => None
        }
    }
}

impl<T: Clone> SimpleLinkedList<T> {
    pub fn rev(&self) -> SimpleLinkedList<T> {
        let mut rv: SimpleLinkedList<T> = SimpleLinkedList::new();
        let mut head = &self.head;
        while head.is_some() {
            rv.push(head.as_ref().unwrap().data.as_ref().unwrap().clone());
            
            head = &head.as_ref().unwrap().next;
        }
        rv
    }
}


impl<'a, T: Clone> From<&'a [T]> for SimpleLinkedList<T> {
    fn from(item: &[T]) -> Self {
        let mut ll = Self::new();
        for el in item.iter()  {
            ll.push(el.clone());
        }
        ll
    }
}

impl<T: Clone> Into<Vec<T>> for SimpleLinkedList<T> {
    fn into(self) -> Vec<T> {
        let mut rv: Vec<T> = Vec::with_capacity(self.length);
        let mut rev = self.rev();

        while rev.peek().is_some() {
            rv.push(rev.pop().unwrap());
        }
        
        rv
    }
}