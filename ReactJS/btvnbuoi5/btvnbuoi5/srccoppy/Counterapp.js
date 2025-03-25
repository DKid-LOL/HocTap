import logo from './logo.svg';
import { useState } from 'react';


function Counterapp() {
  const [counter, setCounter] = useState(1);
  const handleClickUp = () => {
    setCounter (counter + 1);
  }
  const handleClickDown = () => {
    setCounter (counter - 1);
  }
  const handleClickReturn = () => {
    setCounter (0);
  }
  return (
    <div className="App" style={{padding : 30}}>
      <h1>Counter App</h1>
      <h2>{counter}</h2>
      <button className='btn btn-primary btn-sm' onClick={handleClickUp}>Increment!</button>
      <button className='btn btn-danger btn-sm' onClick={handleClickDown}>Decrement!</button>
      <button className='btn btn-reset btn-sm' onClick={handleClickReturn}>Reset!</button>
    </div>
  );
}

export default Counterapp;
