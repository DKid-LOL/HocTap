import React, {useEffect, useState} from 'react';

const List = ({data}) => {
    const [lstTodo, setListTodo] = useState(data);
    useEffect(() => {
        // console.log(data);
        // console.log(lstTodo);
        // setListTodo(data);
    },[]);

    const changeStatusItem = (event,item) => {
        const index = lstTodo.indexOf(item);
        const newList = [...lstTodo];
        newList[index].complete = !newList[index].complete;
        console.log(newList);
        setListTodo(newList);
    }

    return (
        <ul>
            {lstTodo.map((item,index) => (
                <li key={index}>
                    <label  style={item.complete ? {'textDecoration':'line-through','color' : 'red'} : {}}>{item.title}</label> <input type="checkbox" defaultChecked={item.complete}  onChange={(event) => changeStatusItem(event,item)} />
                </li>
            ))}
        </ul>
    )
}

export default List;