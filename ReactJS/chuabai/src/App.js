// import logo from './logo.svg';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import './App.css';
import DataFetcher from './DataFetcher';
import Home from './Home';
import About from './About';
import Header from './Header';
import List from './List';

function App() {
  return (
    <BrowserRouter>
      <div className='root'>
        <Header />
        <Routes >
          <Route path='/' element={<Home />} />
          <Route path='/about' element={<About />} />
        </Routes>

        <DataFetcher >
          <List />
        </DataFetcher>
      </div>
    </BrowserRouter>
  );
}

export default App;