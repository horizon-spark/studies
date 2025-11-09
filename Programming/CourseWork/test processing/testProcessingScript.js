"use strict";

const determineSubtestLevel = (
  points,
  weakTopBorder,
  averageTopBorder,
  goodTopBorder
) => {
  if (points <= weakTopBorder) {
    return 0;
  } else if (points <= averageTopBorder) {
    return 1;
  } else if (points <= goodTopBorder) {
    return 2;
  } else {
    return 3;
  }
};

const calculateConceptualIntuitiveIntellect = (grade, points) => {
  if (grade === 7) {
    return determineSubtestLevel(points, 5, 8, 13);
  } else if (grade === 8) {
    return determineSubtestLevel(points, 5, 9, 14);
  } else if (grade === 9) {
    return determineSubtestLevel(points, 6, 10, 14);
  } else if (grade === 10) {
    return determineSubtestLevel(points, 7, 10, 15);
  } else if (grade === 11) {
    return determineSubtestLevel(points, 7, 10, 16);
  } else {
    return -1;
  }
};

const calculateConceptualLogicalIntellect = (grade, points, isMajor) => {
  if (grade === 7 && !isMajor) {
    return determineSubtestLevel(points, 3, 7, 12);
  } else if (grade === 7 && isMajor) {
    return determineSubtestLevel(points, 4, 8, 13);
  } else if (grade === 8 && !isMajor) {
    return determineSubtestLevel(points, 3, 8, 13);
  } else if (grade === 8 && isMajor) {
    return determineSubtestLevel(points, 4, 9, 14);
  } else if (grade === 9) {
    return determineSubtestLevel(points, 5, 9, 15);
  } else if (grade === 10) {
    return determineSubtestLevel(points, 6, 10, 15);
  } else if (grade === 11) {
    return determineSubtestLevel(points, 7, 10, 16);
  } else {
    return -1;
  }
};

const calculateConceptualCategorization = (grade, points, isMajor) => {
  if (grade === 7) {
    return determineSubtestLevel(points, 3, 7, 12);
  } else if (grade === 8) {
    return determineSubtestLevel(points, 4, 8, 13);
  } else if (grade === 9) {
    return determineSubtestLevel(points, 5, 9, 14);
  } else if ((grade === 10 || grade === 11) && !isMajor) {
    return determineSubtestLevel(points, 5, 10, 15);
  } else if ((grade === 10 || grade === 11) && isMajor) {
    return determineSubtestLevel(points, 5, 11, 17);
  } else {
    return -1;
  }
};

const calculateAbstractIntellect = (grade, points, isMajor) => {
  if (grade === 7) {
    return determineSubtestLevel(points, 4, 8, 13);
  } else if (grade === 8) {
    return determineSubtestLevel(points, 5, 9, 14);
  } else if (grade === 9) {
    return determineSubtestLevel(points, 6, 10, 15);
  } else if (grade === 10 && !isMajor) {
    return determineSubtestLevel(points, 6, 11, 16);
  } else if (grade === 10 && isMajor) {
    return determineSubtestLevel(points, 6, 12, 17);
  } else if (grade === 11 && !isMajor) {
    return determineSubtestLevel(points, 6, 11, 17);
  } else if (grade === 11 && isMajor) {
    return determineSubtestLevel(points, 7, 13, 19);
  } else {
    return -1;
  }
};

const calculateMathematicalIntuition = (grade, points, isMajor) => {
  if (grade === 7) {
    return determineSubtestLevel(points, 5, 8, 12);
  } else if (grade === 8) {
    return determineSubtestLevel(points, 5, 8, 13);
  } else if (grade === 9) {
    return determineSubtestLevel(points, 6, 9, 14);
  } else if ((grade === 10 || grade === 11) && !isMajor) {
    return determineSubtestLevel(points, 7, 10, 15);
  } else if ((grade === 10 || grade === 11) && isMajor) {
    return determineSubtestLevel(points, 8, 12, 17);
  } else {
    return -1;
  }
};

const calculateStructuralVisualIntellect = (points) => {
  return determineSubtestLevel(points, 9, 10, 11);
};

const calculateDynamicVisualIntellect = (points) => {
  return determineSubtestLevel(points, 7, 9, 11);
};

const calculateCombinatorialVisualIntellect = () => {
  return determineSubtestLevel(points, 7, 9, 11);
};

const calculateAbstractVisualIntellect = (grade, points) => {
  if (grade === 7 || grade === 8) {
    return determineSubtestLevel(points, 5, 8, 10);
  } else {
    return determineSubtestLevel(points, 6, 9, 11);
  }
};

const calculateFigurativeSynthesis = (grade, points, isMajor) => {
  if ((grade === 10 || grade === 11) && isMajor) {
    return determineSubtestLevel(points, 5, 10, 16);
  } else {
    return determineSubtestLevel(points, 5, 9, 14);
  }
};

const calculateSpatialAnalysis = (grade, points, isMajor) => {
  if (grade === 9 && isMajor) {
    return determineSubtestLevel(points, 6, 11, 18);
  } else if ((grade === 10 || grade === 11) && isMajor) {
    return determineSubtestLevel(points, 7, 12, 18);
  } else {
    return determineSubtestLevel(points, 5, 9, 16);
  }
};

const calculateDivergentIntellect = (points) => {
  return determineSubtestLevel(points, 2.5, 4.5, 7);
};

const calculateImagination = (points) => {
  return determineSubtestLevel(points, 6, 9, 15);
};

const calculateAwareness = (grade, points, isMajor) => {
  if (isMajor) {
    switch (grade) {
      case 7:
        return determineSubtestLevel(points, 5, 9, 13);
      case 8:
        return determineSubtestLevel(points, 5, 9, 14);
      case 9:
        return determineSubtestLevel(points, 5, 9, 15);
      case 10:
        return determineSubtestLevel(points, 6, 10, 16);
      case 11:
        return determineSubtestLevel(points, 6, 11, 16);
    }
  } else {
    switch (grade) {
      case 7:
        return determineSubtestLevel(points, 4, 8, 13);
      case 8:
        return determineSubtestLevel(points, 4, 9, 13);
      case 9:
        return determineSubtestLevel(points, 5, 9, 14);
      case 10:
        return determineSubtestLevel(points, 6, 10, 15);
      case 11:
        return determineSubtestLevel(points, 6, 10, 16);
    }
  }
  return -1;
};

const calculateRussianReadingSkill = (points) => {
  return determineSubtestLevel(points, 4, 7, 9);
};

const calculateEnglishReadingSkill = (points) => {
  return determineSubtestLevel(points, 4, 7, 9);
};

const calculateLogicalMemory = (grade, points) => {
  switch (grade) {
    case 7:
      return determineSubtestLevel(points, 9, 13, 16);
    case 8:
      return determineSubtestLevel(points, 10, 14, 17);
    case 9:
      return determineSubtestLevel(points, 12, 15, 18);
    case 10:
      return determineSubtestLevel(points, 13, 16, 18);
    case 11:
      return determineSubtestLevel(points, 13, 17, 19);
    default:
      return -1;
  }
};

const calculateInformationProcessingSpeed = (grade, points) => {
  switch (grade) {
    case 7:
      return determineSubtestLevel(points, 36, 45, 57);
    case 8:
      return determineSubtestLevel(points, 38, 48, 59);
    case 9:
      return determineSubtestLevel(points, 40, 50, 64);
    case 10:
      return determineSubtestLevel(points, 44, 54, 69);
    case 11:
      return determineSubtestLevel(points, 49, 62, 77);
    default:
      return -1;
  }
};

const calculateAttentiveness = (grade, points) => {
  if (grade <= 8) {
    return determineSubtestLevel(points, 0.91, 0.95, 0.97);
  } else {
    return determineSubtestLevel(points, 0.92, 0.95, 0.97);
  }
};
