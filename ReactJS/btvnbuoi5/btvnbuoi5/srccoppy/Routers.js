import React from 'react';
import { Route, BrowserRouter as Router, Routes } from 'react-router-dom';
import Home from './Home';
import About from './About';
import Header from './Header';
import Dashboard from './Dashboard';

const MyRoutes = () => {
  return (
    <Router>
      <div>
      <Header/>
        <Routes>
          <Route exact path="/" element={<Home />} />
          <Route path="/about" element={<About />} />
          <Route path="/dashboard" element={<Dashboard />} />
        </Routes>
      </div>
    </Router>
  );
}

export default MyRoutes;