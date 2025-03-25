import React, {useEffect,useState} from 'react';
import List from './List';

const DataFetcher = () => {
    const [data, setData] = useState(null);
    useEffect(() => {
        fetch('http://localhost:3000/data.json')
        .then(response => response.json())
        .then(data => {
            // console.log(data);
            setData(data);
        });
    },[]);

    // console.log(List);
    if(!data){
        return <div>Loading...</div>
    }

    return (
        <div>
            <h5>{data.title}</h5>
            <h2>{data.heading}</h2>
            <p>{data.description}</p>
            <del>$ {data.price}</del>
            <h3>$ {data.price*data.sale/100}</h3>
            <List data={data.array} />
        </div>
    )
}

export default DataFetcher;