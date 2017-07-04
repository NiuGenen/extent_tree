# extent_tree

# extent_list

```
struct ext_node{
    uint16_t ecount;

    struct ext_meta_obj mobjs[ Ext_Node_Degree ];
    struct extent exts[ Ext_Node_Degree ];

    Ext_Node_ID_Type prev;
    Ext_Node_ID_Type next;
}
```
