void myfunc(LinkedList *ll1, LinkedList *ll2) {
    ListNode *a=ll1->head, *b=ll2->head, *c, *d;
    while (ll1 && ll2) {
        c = a->next;
        d = b->next;
        a->next = b->next;
        a=c, b=d;
    }
    ll2->head = b;
    updateSize(ll1);
    updateSize(ll2);
}

void updateSize(linkedList *l) {
    int s=0;
    ListNode *t = l->head;
    while (t) {
        s++;
        t = t->next;
    }
    l->size = s;
}





